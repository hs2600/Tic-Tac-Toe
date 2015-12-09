//Final.cpp
//
//Tic-Tac-Toe Game
//Computer Science 340
//Los Angeles Harbor College
//Written by Horacio Santoyo
//	11/30/15 - First draft

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Declare functions
void splash(); //Splash screen (First screen seen by user with option to continue or exit)
int validateUserInput(int type, string input); //User input validation
void menu(string gameArray[]); //Draws menu
string playerMove();
string computerMove(int counter, int gameArrayHidden[]);
int checkPosition(string position, string gameArray[]);
void processAnswer(int player, string marker, int &counter, string position, string gameArray[], int gameArrayHidden[]);
int checkWin(int counter, string gameArray[]);
void switchPlayer(int &player, string &marker);

int main ()
{
	//Declare variables
	int player, counter, result; 
	string message, marker, turn, continu = "y";

	splash();

	system("CLS");

	while(continu == "y" || continu == "Y")
	{
		player = 1;
		counter = 0;
		marker = "X";
		string gameArray[9] = {"1","2","3","4","5","6","7","8","9"};
		int gameArrayHidden[9] = {0,0,0,0,0,0,0,0,0};

		system("CLS");

		cout << "Who goes first?\n\n";
		cout << "1. Human\n";
		cout << "2. Computer\n\n";

		getline(cin,turn);

		while (validateUserInput(3, turn) != 0)
		{
			cout << "Please enter a valid choice\n";
			getline(cin,turn);
		}

		player = atoi(turn.c_str());

		system("CLS");

		menu(gameArray);

		if(player == 1)
		{
			cout << "It's your turn.  You are '" << marker << "'\nGive me your best move!\n";
		}
		else
			marker = "O";

		while (counter < 9)
		{
			string choice;

			if(player == 1)
				choice = playerMove();
			else
				choice = computerMove(counter, gameArrayHidden);

			while(choice == "0")
			{
				system("CLS");
				menu(gameArray);
				cout << "Enter a valid entry\n" << "your turn\n";	
				choice = playerMove();
			}
			
			if(checkPosition(choice, gameArray) == 1)
			{
			processAnswer(player, marker, counter, choice, gameArray, gameArrayHidden);
			result = checkWin(counter, gameArray);

				if(result == 1)
				{
					system("CLS");
					menu(gameArray);

					if(player == 1)
						cout << "You won!\nGame over!  Play again? y/n\n";
					else
						cout << "The computer won!\nGame over!  Play again? y/n\n";

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
					switchPlayer(player, marker);
					system("CLS");
					menu(gameArray);
					//cout << endl;
					//menu2(gameArrayHidden);
					cout << "It's your turn.  You are '" << marker << "'\nGive me your best move!\n";
				}
			}
			else
			{	
				system("CLS");
				menu(gameArray);
				cout << "Position not available\nMake a different choice\n" << "your turn\n";
			}

			//system("pause");

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


void switchPlayer(int &player, string &marker)
{
	if(player == 1)
	{
		player = 2;
		marker = "O";
	}
	else
	{
		player = 1;
		marker = "X";
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
void processAnswer(int player, string marker, int &counter, string position, string gameArray[], int gameArrayHidden[])
{
	int marker2;

	if(player == 1)
		marker2 = 1;
	else
		marker2 = 3;
	
	int i = atoi(position.c_str());
	i = i - 1;

	gameArray[i] = marker;
	gameArrayHidden[i] = marker2;

	counter++;
}


int validateUserInput(int type, string input)
{
	//1 = number validation
	//2 = name validation
	//3 = turn

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
		case 3:
			if (input.find_first_not_of("12") != string::npos || input.length() == 0)
				return(1);	
			else
				return(0);				
			break;
	}
	return(0);
}


string computerMove(int counter, int gameArrayHidden[])
{
	string choice;
	int position;

    //Check if human has two positions in a row/column/diagonal so we can block the third position
    if (gameArrayHidden[0] + gameArrayHidden[1] + gameArrayHidden[2] == 2)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[3] + gameArrayHidden[4] + gameArrayHidden[5] == 2)
    {
        for (int i = 3; i < 6; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[6] + gameArrayHidden[7] + gameArrayHidden[8] == 2)
    {
        for (int i = 6; i < 9; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[0] + gameArrayHidden[3] + gameArrayHidden[6] == 2)
    {
        for (int i = 0; i < 9; i += 3)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[1] + gameArrayHidden[4] + gameArrayHidden[7] == 2)
    {
        for (int i = 1; i < 9; i += 3)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if(gameArrayHidden[2] + gameArrayHidden[5] + gameArrayHidden[8] == 2)
    {
        for (int i = 2; i < 9; i += 3)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[0] + gameArrayHidden[4] + gameArrayHidden[8] == 2)
    {
        for (int i = 0; i < 9; i += 4)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[2] + gameArrayHidden[4] + gameArrayHidden[6] == 2)
    {
        for (int i = 2; i < 9; i += 4)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else
    {
    	//Human does not have two positions in a row/column/diagonal
    	int i;
        for (i = 0; i < 9; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
        		position = i+1;
				break;
            }
        }

        if(counter % 2 == 0)
        {
	    	//Offensive moves
	        if (gameArrayHidden[1] == 1 && gameArrayHidden[6] == 0 && gameArrayHidden[8] == 0)
	        	position = 9;

	        if (gameArrayHidden[3] == 1 && gameArrayHidden[2] == 0 && gameArrayHidden[8] == 0)
	        	position = 3;

	        if (gameArrayHidden[5] == 1 && gameArrayHidden[0] == 0 && gameArrayHidden[6] == 0)
	        	position = 7;

	        if (gameArrayHidden[7] == 1 && gameArrayHidden[0] == 0 && gameArrayHidden[2] == 0)
	        	position = 1;

	        if (gameArrayHidden[0] == 3 && gameArrayHidden[1] == 0 && gameArrayHidden[2] == 0)
	        	position = 3;

	        if (gameArrayHidden[2] == 3 && gameArrayHidden[1] == 0 && gameArrayHidden[0] == 0)
	        	position = 1;

	        if (gameArrayHidden[0] == 3 && gameArrayHidden[3] == 0 && gameArrayHidden[6] == 0)
	        	position = 7;

	        if (gameArrayHidden[6] == 3 && gameArrayHidden[3] == 0 && gameArrayHidden[0] == 0)
	        	position = 1;

			if (gameArrayHidden[6] == 3 && gameArrayHidden[7] == 0 && gameArrayHidden[8] == 0)
	        	position = 9;
	        
			if (gameArrayHidden[8] == 3 && gameArrayHidden[7] == 0 && gameArrayHidden[6] == 0)
	        	position = 7;

	        if (gameArrayHidden[2] == 3 && gameArrayHidden[5] == 0 && gameArrayHidden[8] == 0)
	        	position = 9;

	        if (gameArrayHidden[8] == 3 && gameArrayHidden[5] == 0 && gameArrayHidden[2] == 0)
	        	position = 3;

			if (gameArrayHidden[0] + gameArrayHidden[4] + gameArrayHidden[8] == 4)
	    	{
		        for (int i = 0; i < 9; i += 4)
		        {
		            if (gameArrayHidden[i] == 0)
		            {
		                position = i+1;
		                break;
		            }
		        }
		    }

	        if (gameArrayHidden[2] + gameArrayHidden[4] + gameArrayHidden[6] == 4)
	    	{
		        for (int i = 2; i < 7; i += 2)
		        {
		            if (gameArrayHidden[i] == 0)
		            {
		                position = i+1;
		                break;
		            }
		        }
		    }

		}
		else
		{
	        //Defensive moves
	        if (gameArrayHidden[4] == 0)
	        	position = 5;

	        if (gameArrayHidden[0] + gameArrayHidden[1] + gameArrayHidden[2] == 3)
	    	{
		        for (int i = 0; i < 2; i += 2)
		        {
		            if (gameArrayHidden[i] == 0)
		            {
		                position = i+1;
		                break;
		            }
		        }
		    }

	        if (gameArrayHidden[0] + gameArrayHidden[3] + gameArrayHidden[6] == 3)
	    	{
		        for (int i = 0; i < 6; i += 6)
		        {
		            if (gameArrayHidden[i] == 0)
		            {
		                position = i+1;
		                break;
		            }
		        }
		    }	    

	        if (gameArrayHidden[6] + gameArrayHidden[7] + gameArrayHidden[8] == 3)
	    	{
		        for (int i = 6; i < 8; i += 2)
		        {
		            if (gameArrayHidden[i] == 0)
		            {
		                position = i+1;
		                break;
		            }
		        }
		    }	    

	        if (gameArrayHidden[2] + gameArrayHidden[5] + gameArrayHidden[8] == 3)
	    	{
		        for (int i = 2; i < 8; i += 6)
		        {
		            if (gameArrayHidden[i] == 0)
		            {
		                position = i+1;
		                break;
		            }
		        }
		    }	    

		}


        //First offensive move
        if(counter == 0)
        {
	       	unsigned seed = unsigned(time(0));
			srand(seed);
			int ii = (rand() % 3) + 1;

			switch(ii)
			{
				case 1:
			        if (gameArrayHidden[4] == 0)
			        	position = 5;
					break;
				case 2:
					if (gameArrayHidden[0] == 0)
			        	position = 1;
					break;
				case 3:
					if (gameArrayHidden[2] == 0)
			        	position = 3;
					break;
			}
		}

    }

   	//Check if computer has two positions in one row/column/diagonal with a third position empty
    if (gameArrayHidden[0] + gameArrayHidden[1] + gameArrayHidden[2] == 6)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[3] + gameArrayHidden[4] + gameArrayHidden[5] == 6)
    {
        for (int i = 3; i < 6; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[6] + gameArrayHidden[7] + gameArrayHidden[8] == 6)
    {
        for (int i = 6; i < 9; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[0] + gameArrayHidden[3] + gameArrayHidden[6] == 6)
    {
        for (int i = 0; i < 9; i += 3)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[1] + gameArrayHidden[4] + gameArrayHidden[7] == 6)
    {
        for (int i = 1; i < 9; i += 3)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if(gameArrayHidden[2] + gameArrayHidden[5] + gameArrayHidden[8] == 6)
    {
        for (int i = 2; i < 9; i += 3)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[0] + gameArrayHidden[4] + gameArrayHidden[8] == 6)
    {
        for (int i = 0; i < 9; i += 4)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }
    else if (gameArrayHidden[2] + gameArrayHidden[4] + gameArrayHidden[6] == 6)
    {
        for (int i = 2; i < 9; i += 4)
        {
            if (gameArrayHidden[i] == 0)
            {
                position = i+1;
                break;
            }
        }
    }

    switch(position)
	{
		case 1:
			choice = "1";
			break;
		case 2:
			choice = "2";
			break;
		case 3:
			choice = "3";
			break;
		case 4:
			choice = "4";
			break;
		case 5:
			choice = "5";
			break;
		case 6:
			choice = "6";
			break;
		case 7:
			choice = "7";
			break;
		case 8:
			choice = "8";
			break;
		case 9:
			choice = "9";
			break;
	}    	

	return choice;
}
