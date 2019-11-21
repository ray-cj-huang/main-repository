#include "grid.h"

const int HORIZ = 0;
const int VERT = 1;

const int FG = 0;
const int BG = 1;

bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg);

/*void plotHorizontalLine(int y, int x, int distance, char ch);
void plotVerticalLine(int r, int c, int distance, char ch);
void plotRectangle(int r, int c, int height, int width, char ch);*/

int main()
{
	setSize(15, 12);
	const int middle = getCols() / 2;

	draw();
}
/* void plotHorizontalLine(int y, int x, int distance, char ch)
{
	for (int i = 0; i < distance; i++)
	{
		setChar(y, x + i, ch);
	}
}
void plotVerticalLine(int y, int x, int distance, char ch)
{
	for (int i = 0; i < distance; i++)
	{
		setChar(y + i, x, ch);
	}
}
void plotRectangle(int r, int c, int height, int width, char ch)
{
	plotVerticalLine(r, c, height, ch);
	plotHorizontalLine(r, c, width, ch);
	plotVerticalLine(r, c+width-1, height, ch);
	plotHorizontalLine(r+height-1, c, width, ch);
} */