#include "grid.h"
#include <iostream>
//#include <cassert> //used to test phase 2
#include <cctype>
#include <string>

using namespace std;

const int HORIZ = 0;
const int VERT = 1;

const int FG = 0;
const int BG = 1;

//Warm Up Declaration
/*
void plotHorizontalLine(int y, int x, int distance, char ch);
void plotVerticalLine(int r, int c, int distance, char ch);
void plotRectangle(int r, int c, int height, int width, char ch);
*/

bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg);
int performCommands(string commandString, char& plotChar, int& mode, int& badPos);

//testing phase 2
/*
int main()
{
	setSize(15, 15);
	
	
	clearGrid();
	plotLine(15, 15, -15, HORIZ, 'H', FG);
	plotLine(15, 1, 2, HORIZ, 'i', BG);
	plotLine(4, 4, -3, VERT, '!', FG);
	plotLine(1, 4, 5, HORIZ, 'B', BG);
	draw();

	cout << plotLine(15, 15, -15, HORIZ, 'H', FG) << endl;
	cout << plotLine(15, 1, 2, HORIZ, 'i', BG) << endl;
	cout << plotLine(4, 4, -3, VERT, '!', FG) << endl;
	cout << plotLine(1, 4, 0, HORIZ, 'B', BG) << endl;
	clearGrid();
	assert(plotLine(1, 1, 0, HORIZ, 'H', FG));
	assert(plotLine(1, 2, 0, HORIZ, 'i', FG));
	assert(plotLine(1, 3, 0, HORIZ, '!', FG));
	draw();  //  displays  Hi!  in the top row of the grid
	assert(plotLine(1, 3, 0, HORIZ, ' ', FG));
	draw();  //  displays  Hi   in the top row of the grid
	assert(plotLine(1, 1, 20, HORIZ, ' ', BG));
	draw();  //  displays  Hi   in the top row of the grid
	assert(!plotLine(1, 1, 10, HORIZ, '\n', FG));
	draw();  //  displays  Hi   in the top row of the grid
	
}
*/

//testing phase 3
int main()
{
	setSize(20, 30);
	char currentChar = '*';
	int currentMode = FG;

	for (;;)
	{
		cout << "Enter a command string: ";
		string cmd;
		getline(cin, cmd);

		if (cmd == "")
			break;
	
		int position;
		int status = performCommands(cmd, currentChar, currentMode, position);
		switch (status)
		{
			case 0:
				draw();
				break;
			case 1:
				cout << "Syntax error at position " << position + 1 << endl;
				break;
			case 2:
				cout << "Cannot perform command at position " << position + 1 << endl;
				break;
			default:
				// It should be impossible to get here.
				cerr << "performCommands returned " << status << "!" << endl;
		}
	}
}


bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg)
{
	if (!isprint(plotChar)) //make sure character can be printed
		return false;
	if (dir != HORIZ && dir != VERT) //make sure direction is horizontal or vertical
		return false;
	if (fgbg != FG && fgbg != BG) //make sure it's either foreground or background
		return false;
	if (dir == HORIZ) //make sure it doesn't go over the grid horizontally
	{
		if ((c + distance < 1) || (c + distance > getCols())) //didn't use checkPos because of extra codes
			return false;
	}
	if (dir == VERT) //make sure it doesn't go over the grid vertically
	{
		if ((r + distance < 1) || (r + distance > getRows())) //didn't use checkPos because of extra codes
			return false;
	}

	//Horizontal & Vertical
	if (distance >= 0) //moving in the positive direction (right, down)
	{
		for (int i = 0; i != distance + 1; i++)
		{
			if (dir == HORIZ)
			{
				if (fgbg == BG && getChar(r, c + i) != ' ') //background
					continue;
				setChar(r, c + i, plotChar); //pos horizontal (right)
			}
			if (dir == VERT)
			{
				if (fgbg == BG && getChar(r + i, c) != ' ') //background
					continue;
				setChar(r + i, c, plotChar); //pos vertical (down)
			}
		}
	}
	else //moving in the negative direction (left, up)
	{
		for (int i = 0; i != -distance + 1; i++) //distance is negative -> make it pos
		{
			if (dir == HORIZ) //neg horizontal (left)
			{
				if (fgbg == BG && getChar(r, c - i) != ' ') //background
					continue;
				setChar(r, c - i, plotChar);
			}
			if (dir == VERT) //neg vertical (up)
			{
				if (fgbg == BG && getChar(r - i, c) != ' ') //background
					continue;
				setChar(r - i, c, plotChar);
			}
		}
	}
	return true;
}

int performCommands(string commandString, char& plotChar, int& mode, int& badPos)
{
	if (commandString == "") //if commandString is empty
		return 0;

	//turn the input into all lowercases
	string cmd;
	for (int i = 0; i != commandString.size(); i++)
		cmd += tolower(commandString[i]);

	static int row = 1;
	static int column = 1;

	//LOOP
	for (int i = 0; i != cmd.size(); i++)
	{
		if (cmd[i] == 'h' || cmd[i] == 'v') //horizontal or vertical
		{
			int dir = HORIZ; //direction as horizontal
			if (cmd[i] == 'v')
				dir = VERT; //direction as vertical

			if ((i + 1 != cmd.size()) && cmd[i + 1] == '-') //negative number
			{
				if ((i + 2 != cmd.size()) && isdigit(cmd[i + 2]))
				{
					if ((i + 3 != cmd.size()) && isdigit(cmd[i + 3])) //double digits
					{
						//convert char to int
						int temp = 0; 
						int tens = cmd[i + 2] - '0';
						int ones = cmd[i + 3] - '0';
						temp = 10 * tens + ones;

						if (!plotLine(row, column, -temp, dir, plotChar, mode)) //command error
						{
							badPos = i;
							return 2;
						}

						if (cmd[i] == 'v')
							row += -temp;
						if (cmd[i] == 'h')
							column += -temp;
						
						//account for '-' and two digits
						i += 3;
						continue;
					}

					//single digit

					//convert char to int
					int temp = 0;
					int ones = cmd[i + 2] - '0';
					temp = ones;

					if (!plotLine(row, column, -temp, dir, plotChar, mode)) //command error
					{
						badPos = i;
						return 2;		
					}

					if (cmd[i] == 'v')
						row += -temp;
					if (cmd[i] == 'h')
						column += -temp;

					//account for '-' and one digit 
					i += 2;
					continue;
				}
				else
				{
				badPos = i + 2;
				return 1;
				}
			}
			else if ((i + 1 != cmd.size()) && isdigit(cmd[i + 1])) //positive number
			{
				if ((i + 2 != cmd.size()) && isdigit(cmd[i + 2])) //double digits
				{
					//convert char to int
					int temp = 0;
					int tens = cmd[i + 1] - '0';
					int ones = cmd[i + 2] - '0';
					temp = 10 * tens + ones;

					if (!plotLine(row, column, temp, dir, plotChar, mode)) //command error
					{
						badPos = i;
						return 2;
					}
					
					if (cmd[i] == 'v')
						row += temp;
					if (cmd[i] == 'h')
						column += temp;

					//acount for two digits
					i += 2;
					continue;
				}

				//single digit

				//convert char to int
				int temp = 0;
				int ones = cmd[i + 1] - '0';
				temp = ones;

				if (!plotLine(row, column, temp, dir, plotChar, mode)) //command error
				{
					badPos = i;
					return 2;
				}

				if (cmd[i] == 'v')
					row += temp;
				if (cmd[i] == 'h')
					column += temp;

				//acount for a digit
				i++;
				continue;
			}
			else
			{
				badPos = i+1;
				return 1;
			}
		}

		if (cmd[i] == 'f' || cmd[i] == 'b')
		{
			if (i + 1 != cmd.size() && isprint(cmd[i + 1]))
			{
				if (cmd[i] == 'b') //set foreground
					mode = BG;
				else
					mode = FG; //set background
				
				plotChar = cmd[i + 1];

				//account for a character
				i++;
				continue;
			}
			
			//syntax error (need a character after f/b)
			badPos = i + 1;
			return 1;
		}
		
		if (cmd[i] == 'c')
		{	
			clearGrid();
			row = 1;
			column = 1;
			plotChar = '*';
			continue;
		}

		badPos = i;
		return 1;
	
	}

	return 0;
}

//Warm Up
/*
void plotHorizontalLine(int r, int c, int distance, char ch)
{
	for (int i = 0; i < distance; i++)
	{
		setChar(r, c + i, ch);
	}
}

void plotVerticalLine(int r, int c, int distance, char ch)
{
	for (int i = 0; i < distance; i++)
	{
		setChar(r + i, c, ch);
	}
}

void plotRectangle(int r, int c, int height, int width, char ch)
{
	plotVerticalLine(r, c, height, ch);
	plotHorizontalLine(r, c, width, ch);
	plotVerticalLine(r, c + width - 1, height, ch);
	plotHorizontalLine(r + height - 1, c, width, ch);
}
*/