// Snake-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <Windows.h>
#include <list>
using namespace std;

int nScreenWidth = 120;
int nScreenHeight = 80;

struct sSnakeSegment
{
	int x;
	int y;
};

int main()
{
	// Create Screen Buffer
	wchar_t* screen = new wchar_t[nScreenHeight * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	list<sSnakeSegment> snake{ {60,15}, {61,15}, {62,15}, {63,15}, {64,15}, {65, 15}, {66,15}, {67, 15}, {68,15}, {69,15} };
	int nFoodX = 30;
	int nFoodY = 15;
	int nScore = 0;
	int nSakeDirection = 3;
	bool bDead = false;

	while (1)
	{
		// Timing & Input

		// Game Logic

		// Display to Player
		// Clear Screen
		for (int i = 0; i < nScreenWidth * nScreenHeight; i++)
		{
			screen[i] = L' ';
		}

		// Draw Stats & Border
		for (int i = 0; i < nScreenWidth; i++)
		{
			screen[i] = L'=';
			screen[2 * nScreenWidth + i] = L'=';
		}
		wsprintf(&screen[nScreenWidth + 5], L"SNAKE GAME               SCORE: %d", nScore);

		// Display Frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}

	// screen[nScreenWidth * nScreenHeight - 1] = '\0';

	return 0;
}
