// Snake-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <Windows.h>
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

	while (1)
	{
		// Timing & Input

		// Game Logic

		// Display to Player

		// Display Frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}

	// screen[nScreenWidth * nScreenHeight - 1] = '\0';

	return 0;
}
