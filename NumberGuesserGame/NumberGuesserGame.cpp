//This is a function that Visual Studio uses.
//Please delete this if you planning to run this on other app.
#include "stdafx.h"

//Adding standard library for I/O and console I/O. Also adding string lib for string function.
#include <iostream>
#include <conio.h>
#include <string>

//Add library to measure time
#include <ctime>
#include <chrono>

//Add library for random function
#include <random>

using namespace std;

//This function was used for debugging.
/*
bool DEBUG_COMPAREGREATER(int value1, int value2)
{
	return value1 > value2;
}

bool DEBUG_COMPARELESSER(int value1, int value2)
{
	return value1 < value2;
}
*/

//Function that will ask input from user, checks if it was a number, and return it. Source : http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
int inputNumberFromCIN()
{
	int i;
	while (!(cin >> i)) {
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Invalid data type! Please enter the number again!" << endl;
	}
	return i;
}

int main()
{
	cout << "=======================================================" << endl;
	cout << "		Number Guessing Game" << endl;
	cout << "=======================================================" << endl;
	cout << endl;

	//This function is only supported on C++11. for compability, use time(0) instead.
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();

	//Generate a number using Mersenne Twister Engine.
	mt19937_64 mtRand(seed);

	//Gistribute the number and assign to randomNumber
	uniform_int_distribution<int> distributeResult(0, 500);
	int randomNumber = distributeResult(mtRand);

	//this engine was rather outdated. also it tends to generate near maximum limit. Also the maximum number it can generate is 32767.
	//In a nutshell, rand() is sucks. Don't use it.
	//srand(seed);
	//int randomNumber = rand() % 500;

	//variable to store user input, and variable to count user guess try.
	int inputNumber;
	int guessTry = 1;

	//Initiating variable to define time limit.
	double timeLimit = 120;

	cout << "The number had been choosen. Try to pick a number." << endl;

	//Store the time when the quiz start.
	time_t startTime = clock();

	//cout << "DEBUG : " << randomNumber << endl;

	while (true)
	{
		inputNumber = inputNumberFromCIN();

		//cout << "DEBUG : " << inputNumberFromCIN();

		//cout << "DEBUG : " << inputNumber << endl;

		//cout << "DEBUG : " << DEBUG_COMPAREGREATER(inputNumber, randomNumber) << endl;
		//cout << "DEBUG : " << DEBUG_COMPARELESSER(inputNumber, randomNumber) << endl;

		//Check if the input matches the  random number picked. If yes, breaks the loop. 
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

	if (!(elapsedSeconds > timeLimit))
	{
		cout << "Yay! You've picked the right one!. You've guessed the number in " << guessTry << " guess." << endl;
		cout << "Also you've guessed the number in " << elapsedSeconds << " seconds." << endl;
		cout << endl;
		cout << "FINAL SCORE : " << scoreResult << endl;
	}
	else
	{
		cout << "Yay! You've picked the right one!. But you've guessed a bit too late. Try again next time! ~☆" << endl;
	}

	_getch();

}