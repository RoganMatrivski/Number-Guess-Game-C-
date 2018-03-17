#include "stdafx.h"

#include <iostream>
#include <conio.h>
#include <string>
#include <functional>

//Add library to measure time
#include <ctime>
#include <chrono>

//Add library for random function
#include <random>

using namespace std;

bool DEBUG_COMPAREGREATER(int value1, int value2)
{
	return value1 > value2;
}

bool DEBUG_COMPARELESSER(int value1, int value2)
{
	return value1 < value2;
}

int main()
{
	cout << "=======================================================" << endl;
	cout << "		Number Guessing Game" << endl;
	cout << "=======================================================" << endl;
	cout << endl;

	//note that this function is only supported on C++11. for compability, use time(0) instead.
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();

	//generate a number using Mersenne Twister Engine.
	mt19937 mtRand(seed);

	//distribute the number and assign to randomNumber
	uniform_int_distribution<int> distributeResult(0, 500);
	int randomNumber = distributeResult(mtRand);

	//this engine was rather outdated. also it tends to generate near maximum limit.
	//srand(seed);
	//int randomNumber = rand() % 500;

	int inputNumber;
	int guessTry = 1;

	double timeLimit = 120;

	cout << "The number had been choosen. Try to pick a number." << endl;

	time_t startTime = clock();

	cout << "DEBUG : " << randomNumber << endl;

	while (true)
	{
		cin >> inputNumber;

		//cout << "DEBUG : " << inputNumber << endl;

		//cout << "DEBUG : " << DEBUG_COMPAREGREATER(inputNumber, randomNumber) << endl;
		//cout << "DEBUG : " << DEBUG_COMPARELESSER(inputNumber, randomNumber) << endl;

		if (inputNumber == randomNumber)
		{
			break;
		}

		if (inputNumber < randomNumber)
		{
			cout << "The number you picked was lower than the number choosen. Try a higher number." << endl;
			guessTry++;
		}

		if (inputNumber > randomNumber)
		{
			cout << "The number you picked was higher than the number choosen. Try a lower number." << endl;
			guessTry++;
		}
	}
	
	time_t endTime = clock();

	double elapsedSeconds = double(endTime - startTime) / CLOCKS_PER_SEC;

	//double scoreResult = (((timeLimit - elapsedSeconds) / (guessTry / 4)) / timeLimit) * 100;

	double scoreResult = ((timeLimit - elapsedSeconds) / (timeLimit + (guessTry * 10))) * 1000000;
	//double test1 = (timeLimit - elapsedSeconds);

	//cout << "DEBUG : " << test1 << endl;


	cout << "Yay! You've picked the right one!. You've guessed the number in " << guessTry << " guess." << endl;
	cout << "Also you've guessed the number in " << elapsedSeconds << " seconds." << endl;
	cout << endl;
	cout << "FINAL SCORE : " << scoreResult << endl;

	_getch();

}