#include "utilities.h"
#include <iostream>
#include <cctype>
#include <cstring>
#pragma warning(disable:6262)
#define _CRT_SECURE_NO_DEPRECATE

using namespace std;

const char WORDFILENAME[] = "C:/Users/rayhu/Desktop/CS 31/Projects/Assignment 5/words.txt";

const int MAXWORDS = 9000;

int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum);
bool isNotFourToSixLowercaseChar(const char input[MAXWORDLEN + 2]);
bool isNotValid(const char input[MAXWORDLEN + 1], const char validList[][MAXWORDLEN + 1], int nWords);

int calculateFlower(const char input[MAXWORDLEN + 1], const char mysteryWord[MAXWORDLEN + 1]);
int calculateBee(const char input[MAXWORDLEN + 1], const char mysteryWord[MAXWORDLEN + 1]);

bool notFound(int value, int list[]);

int main()
{	
	char w[MAXWORDS][MAXWORDLEN+1];
	int nWords = getWords(w, MAXWORDS, WORDFILENAME); //getWords will not return an int greater than maxWords
	
	if (nWords < 1)
	{
		cout << "No words were loaded, so I can't play the game." << endl;
	}
	else
	{
		cout << "How many rounds do you want to play? ";
		int numRound;
		cin >> numRound;
		cin.ignore(10000, '\n');
		if (numRound < 0)
			cout << "The number of rounds must be positive." << endl;
		else
		{
			int totalNumOfTrials = 0;
			int minTrials = 0;
			int maxTrials = 0;
			for (int r = 1; r <= numRound; r++)
			{
				int temp = randInt(0, nWords-1);
				int wordLength = strlen(w[temp]);
				//cerr << w[temp] << endl; //to test words
				cout << "\nRound " << r << endl;
				cout << "The mystery word is " << wordLength << " letters long." << endl;

				int numOfTrials = playOneRound(w, nWords, temp);
				if (r == 1)
				{
					minTrials = numOfTrials;
					maxTrials = numOfTrials;
				}

				if (numOfTrials > maxTrials)
					maxTrials = numOfTrials;
				if (numOfTrials < minTrials)
					minTrials = numOfTrials;

				if (numOfTrials == 1)
					cout << "You got it in 1 try." << endl;
				else
					cout << "You got it in " << numOfTrials << " tries." << endl;

				totalNumOfTrials += numOfTrials;

				cout.setf(ios::fixed);
				cout.precision(2);
				
				cout << "Average: " << static_cast<double>(totalNumOfTrials) / r << ", minimum: " << minTrials << ", maximum: " << maxTrials << endl;

			}
		}
	}
	
}

int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
{
	if (wordnum < 0 || wordnum >= nWords)
		return -1;

	int numTrials = 0;

	for (;;) //each trial
	{
		
		

		cout << "Trial word: ";

		char input[MAXWORDLEN + 2];
		
		cin.getline(input, MAXWORDLEN + 2);

		if (isNotFourToSixLowercaseChar(input))
		{
			cout << "Your trial word must be a word of 4 to 6 lower case letters." << endl;
		}
		else if (isNotValid(input, words, nWords))
		{
			cout << "I don't know that word." << endl;
		}
		else
		{
			numTrials++;
			
			if (strcmp(input, words[wordnum]) == 0) //if the input is the same as the mystery word -> exit loop
				break;
		
			int flower = calculateFlower(input, words[wordnum]);
			int bee = calculateBee(input, words[wordnum]);

			cout << "Flowers: " << flower << ", Bees: " << bee << endl; //print flowers & bees
		}
		
	}

	return numTrials;
}

//The input string has to be all lowercase letters with four to six number of char
bool isNotFourToSixLowercaseChar(const char input[MAXWORDLEN + 2])
{
	//If any char is not lowercase, return true for not being 4-6 lowercase char
	for (int i = 0; input[i] != '\0'; i++)
	{		
		if (islower(input[i]) == 0)
		{
			return true;
		}
	}
	//After checking all chars are lowercases, if the char after the 4-6 characters is a null character, that means the total number of chars is in the range 4-6 
	if (strlen(input) < 4 || strlen(input) > 6)
		return true;
	return false;
}

//The input string has to be one of the words in the array of valid words, which are those that getWords puts into the array
bool isNotValid(const char input[MAXWORDLEN + 1], const char validList[][MAXWORDLEN + 1], int nWords)
{
	for (int i = 0; i < nWords; i++)
	{
		if (strcmp(validList[i], input) == 0)
			return false;
	}
	return true;
}

int calculateFlower(const char input[MAXWORDLEN + 1], const char mysteryWord[MAXWORDLEN + 1])
{
	int flower = 0;
	for (int i = 0; input[i] != '\0' && mysteryWord[i] != '\0'; i++)
	{
		if (input[i] == mysteryWord[i])
		{
			flower++;
		}
	}
	return flower;
}

int calculateBee(const char input[MAXWORDLEN + 1], const char mysteryWord[MAXWORDLEN + 1])
{
	int bee = 0;
	
	int beeInput[MAXWORDLEN+1];
	int beeWords[MAXWORDLEN+1];
	
	//initalized to all -1
	for (int i = 0; i < MAXWORDLEN + 1; i++)
	{
		beeInput[i] = -1;
		beeWords[i] = -1;
	}

	for (int i = 0; mysteryWord[i] != '\0'; i++)
	{
		for (int k = 0; input[k] != '\0'; k++)
		{
			if (i != k && mysteryWord[i] == input[k] && notFound(i, beeWords) && notFound(k, beeInput))
			{
				bee++;
				break;
			}
		}
			
		
	}
	return bee;
}

bool notFound(int value, int list[])
{
	for (int i = 0; i < MAXWORDLEN; i++)
	{
		if (value == list[i])
			return false;
	}
	for (int c = 0; c < MAXWORDLEN; c++)
	{
		if (list[c] == -1)
		{
			list[c] = value;
			return true;
		}
	}
	return false;
}