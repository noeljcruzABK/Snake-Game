// Snake-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <Windows.h>
#include <list>
#include <thread>
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
	int nSnakeDirection = 3;
	bool bDead = false;
	bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;

	while (1)
	{
		// TIMING & INPUT
		this_thread::sleep_for(200ms);

		// Get Input
		bKeyRight = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;
		bKeyLeft = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;

		if (bKeyRight && !bKeyRightOld)
		{
			nSnakeDirection++;
			if (nSnakeDirection == 4) nSnakeDirection = 0;
		}

		if (bKeyLeft && !bKeyLeftOld)
		{
			nSnakeDirection--;
			if (nSnakeDirection == -1) nSnakeDirection = 3;
		}

		bKeyRightOld = bKeyRight;
		bKeyLeftOld = bKeyLeft;

		// GAME LOGIC
		// Update Snake Position
		switch (nSnakeDirection)
		{
		case 0: // up
			snake.push_front({ snake.front().x, snake.front().y - 1 });
			break;
		case 1: // right
			snake.push_front({ snake.front().x + 1, snake.front().y });
			break;
		case 2: // down
			snake.push_front({ snake.front().x, snake.front().y + 1 });
			break;
		case 3: // left
			snake.push_front({ snake.front().x - 1, snake.front().y });
			break;
		}

		// Chop off Snake's Tail
		snake.pop_back();

		// DISPLAY TO PLAYER
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

		// Draw Snake Body
		for (auto s : snake)
		{
			screen[s.y * nScreenWidth + s.x] = bDead ? L'+' : L'O';
		}

		// Draw Snake Head
		screen[snake.front().y * nScreenWidth + snake.front().x] = bDead ? L'X' : L'@';

		// Draw Food
		screen[nFoodY * nScreenWidth + nFoodX] = L'%';

		// Display Frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}

	// screen[nScreenWidth * nScreenHeight - 1] = '\0';

	return 0;
}
