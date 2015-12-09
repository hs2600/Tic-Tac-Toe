//Final.cpp
//
//Tic-Tac-Toe Game
//Computer Science 340
//Los Angeles Harbor College
//Written by Horacio Santoyo
//	11/08/15 - First draft

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Declare functions
void splash(); //Splash screen (First screen seen by user with option to continue or exit)
string user(int player); //Gets name from user (With input validation)
int validateUserInput(int type, string input); //User input validation
void menu(string gameArray[]); //Draws menu
string playerMove();
int checkPosition(string position, string gameArray[]);
void processAnswer(int player, int &counter, string position, string gameArray[]);
int checkWin(int counter, string gameArray[]);
void changePlayer(int &player, string &playerName, string player1, string player2, string &marker);


int main ()
{
	//Declare variables
	int player, counter, result; 
	string player1, player2, playerName, marker, continu = "y";

	splash();

	system("CLS");
	player1 = user(1);
	player2 = user(2);


	while(continu == "y" || continu == "Y")
	{
		playerName = player1;
		player = 1;
		counter = 0;
		marker = "X";
		string gameArray[9] = {"1","2","3","4","5","6","7","8","9"};

		system("CLS");
		menu(gameArray);
		cout << "It's " << playerName << "'s turn.  You are '" << marker << "'\nGive me your best move!\n";

		while (counter < 9)
		{
			string choice = playerMove();

			while(choice == "0")
			{
				system("CLS");
				menu(gameArray);
				cout << "Enter a valid entry\n" << playerName << "'s turn\n";
				choice = playerMove();
			}
			
			if(checkPosition(choice, gameArray) == 1)
			{
			processAnswer(player, counter, choice, gameArray);
			result = checkWin(counter, gameArray);

				if(result == 1)
				{
					system("CLS");
					menu(gameArray);
					cout << playerName << " won!\nGame over!  Play again? y/n\n";
					counter = 9;
				}
				else if (result == 2)
				{
					system("CLS");
					menu(gameArray);
					cout << "It's a tie!\nGame over!  Play again? y/n\n";
				}
				else
				{
					changePlayer(player, playerName, player1, player2, marker);
					system("CLS");
					menu(gameArray);
					cout << "It's " << playerName << "'s turn.  You are '" << marker << "'\nGive me your best move!\n";
				}
			}
			else
			{	
				system("CLS");
				menu(gameArray);
				cout << "Position not available\nMake a different choice\n" << playerName << "'s turn\n";
			}

		}
		getline(cin, continu);
	}

	system("CLS");
	cout << "Good bye!\n\n";
	system("pause");
	return(0);
}


//Splash
void splash()
{
	string input;
	int getInput = 0;

	system("CLS");

	cout << "***************************\n";
	cout << "***************************\n";
	cout << "***************************\n";
	cout << "****                   ****\n";
	cout << "****    TIC-TAC-TOE    ****\n";
	cout << "****        By:        ****\n";
	cout << "****  Horacio Santoyo  ****\n";
	cout << "****                   ****\n";
	cout << "***************************\n";
	cout << "***************************\n";
	cout << "***************************\n\n";

system("pause");

}


//Function to get player's name
string user(int player)
{
	string name;
	int getInput;

	cout << "Player " << player << ", enter your name: ";

	getline(cin, name);
	getInput = 1;

	while(getInput ==1)
	{
		if(validateUserInput(2,name) == 1)
		{
			cout << "\nPlease enter a valid name: ";
			getline(cin, name);
		}
		else if(validateUserInput(2,name) == 2)
		{
		    cout << "\nPlease enter only your first name: ";
			getline(cin, name);
		}
		else
		{
			getInput = 0;
		}
	}

	system("CLS");
	return(name);
}


void changePlayer(int &player, string &playerName, string player1, string player2, string &marker)
{
	if(player == 1)
		{
			player = 2;
			playerName = player2;
			marker = "O";
		}
	else
		{
			player = 1;
			marker = "X";
			playerName = player1;
		}
}


void menu(string gameArray[])
{
	cout << "      TIC-TAC-TOE\n\n";
	//cout << "        |-----|\n";
	cout << "         |   |\n";
	cout << "       " << gameArray[0] << " | " << gameArray[1] << " | " << gameArray[2] << "\n";
	cout << "      ___|___|___\n";
	cout << "         |   |\n";	
	cout << "       " << gameArray[3] << " | " << gameArray[4] << " | " << gameArray[5] << "\n";
	cout << "      ___|___|___\n";
	cout << "         |   |\n";
	cout << "       " << gameArray[6] << " | " << gameArray[7] << " | " << gameArray[8] << "\n";
	cout << "         |   |\n\n";
}


string playerMove()
{
	string input;
	int getInput;

	getline(cin, input);
	getInput = 1;

	while(getInput == 1)
	{
		if(validateUserInput(1,input) == 1 || atoi(input.c_str()) > 9)
		{
			getInput = 0;
			return "0";
		}
		else
		{	
			getInput = 0;
			return input;
		}
	}
	return "error";
}


int checkWin(int counter, string gameArray[])
{
/*	
		|-----|
        |0|1|2|
		|-----|
        |3|4|5|
		|-----|
        |6|7|8|
		|-----|

*/

if(	
	(gameArray[0] == gameArray[3] && gameArray[0] == gameArray[6]) ||
	(gameArray[0] == gameArray[1] && gameArray[0] == gameArray[2]) ||
	(gameArray[0] == gameArray[4] && gameArray[0] == gameArray[8]) ||
	(gameArray[1] == gameArray[4] && gameArray[1] == gameArray[7]) ||
	(gameArray[2] == gameArray[4] && gameArray[2] == gameArray[6]) ||
	(gameArray[2] == gameArray[5] && gameArray[2] == gameArray[8]) ||
	(gameArray[3] == gameArray[4] && gameArray[3] == gameArray[5]) ||
	(gameArray[6] == gameArray[7] && gameArray[6] == gameArray[8]) 
	)
	{
	return 1;
	}
else if(counter==9)
	{
	return 2;
	}
else
	return 0;
}


int checkPosition(string position, string gameArray[])
{

	int i = atoi(position.c_str());
	i = i - 1;

	if(gameArray[i] == position)
		{
			return (1);
		}
	else
		{
			return(0);
		}
}


//Process user's answer
void processAnswer(int player, int &counter, string position, string gameArray[])
{
	string marker;

	if(player == 1)
		marker = "X";
	else
		marker = "O";

	int i = atoi(position.c_str());
	i = i - 1;

	gameArray[i] = marker;
	counter++;
}


int validateUserInput(int type, string input)
{
	//1 = number validation
	//2 = name validation

	size_t pos = input.find_first_of(" ");
	int spac = input.find(" ",0);

	switch (type)
	{
		case 1:
			if (input.find_first_not_of("123456789") != string::npos || input.length() == 0)
				return(1);	
			else
				return(0);				
			break;
		case 2:
			if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYXZ ") != string::npos || input.length() == 0 || pos < 1)
				return(1);	
			else
			{
				if (spac > 0)
					return(2);	
				else
					return(0);	
			}
			break;
	}
	return(0);
}
