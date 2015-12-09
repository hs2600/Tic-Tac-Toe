//Final V3.cpp
//
//Tic-Tac-Toe Game
//Computer Science 340
//Los Angeles Harbor College
//Written by Horacio Santoyo
//	12/07/15 - First draft

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Declare functions
void splash(); //Splash screen
int menu();
string user(int player); //Gets name from user (With input validation)
int pickSide(); //For human against computer game, allows to choose who starts first
void whichGrid(int gameType, string gameArray[], string bigArray[][12]); //Draws small or big grid depending on the game type
void displayGrid(string gameArray[]); //Draws small grid
string playerMove(); //Handle's players next move
string computerMove(int counter, int gameArrayHidden[]); //Handles computer's moves with an algorithm (uses defensive and offensive moves)
bool checkPosition(string position, string gameArray[]); //Checks position to make sure it's empty
void processAnswer(int player, string marker, int &counter, string position, string gameArray[], int gameArrayHidden[]); //Updates arrays
int checkWin(int counter, string gameArray[]); //Checks for a win or a tie
void switchPlayer(int &player, string &playerName, string player1, string player2, string &marker); //Switches players after every move
void resetBigArray(string bigArray[][12]); //Resets two dimensional array
void displayBigArray(string bigArray[][12]); //Draws big grid
void updateBigArray(string choice, string marker, string bigArray[][12]); //Updates big array with X or O
int validateUserInput(int type, string input); //User input validation


int main ()
{
	//Declare variables
	int player, counter, result, gameType;
	string player1, player2, playerName, marker, continu;

	splash();

	gameType = menu();

	while (gameType != 4)	
	{
		if (gameType == 1)
		{
			player = 1;
			player1 = user(1);
			player2 = user(2);
		}

		continu = "y";

		while(continu == "y" || continu == "Y")
		{
			playerName = player1;
			player = 1;
			marker = "X";
			counter = 0;
			string gameArray[9] = {"1","2","3","4","5","6","7","8","9"};
			int gameArrayHidden[9] = {0,0,0,0,0,0,0,0,0};
			string bigArray[15][12];
			resetBigArray(bigArray);

			if(gameType != 1)
				player = pickSide();

			whichGrid(gameType, gameArray, bigArray);

			if(gameType == 1)
				cout << "It's " << playerName << "'s turn.  You are '" << marker << "'\nGive me your best move!\n";
			else
			{
				if(player == 1)
					cout << "It's your turn.  You are '" << marker << "'\nGive me your best move!\n";
				else
					marker = "O";
			}

			while (counter < 9)
			{
				string choice;

				if(gameType == 1)
				{
					choice = playerMove();
				}
				else
				{
					if(player == 1)
						choice = playerMove();
					else
						choice = computerMove(counter, gameArrayHidden);
				}

				while(choice == "0")
				{
					whichGrid(gameType, gameArray, bigArray);
					cout << "Enter a valid entry\n" << "your turn\n";	
					choice = playerMove();
				}
				
				if(checkPosition(choice, gameArray) == true)
				{
				processAnswer(player, marker, counter, choice, gameArray, gameArrayHidden);
				updateBigArray(choice, marker, bigArray);
				result = checkWin(counter, gameArray);

					if(result == 1)
					{
						whichGrid(gameType, gameArray, bigArray);
						
						if(gameType == 1)
						{
							cout << playerName << " won!\nGame over!  Play again? y/n\n";
						}
						else
						{
							if(player == 1)
								cout << "You won!\nGame over!  Play again? y/n\n";
							else
								cout << "The computer won!\nGame over!  Play again? y/n\n";
						}

							counter = 9;
					}
					else if (result == 2)
					{
						whichGrid(gameType, gameArray, bigArray);
						cout << "It's a tie!\nGame over!  Play again? y/n\n";
					}
					else
					{
						switchPlayer(player, playerName, player1, player2, marker);
						whichGrid(gameType, gameArray, bigArray);

						if(gameType == 1)
						{
							cout << "It's " << playerName << "'s turn.  You are '" << marker << "'\nGive me your best move!\n";
						}
						else
						{
							cout << "It's your turn.  You are '" << marker << "'\nGive me your best move!\n";
						}
					}
				}
				else
				{	
					whichGrid(gameType, gameArray, bigArray);
					cout << "Position not available\nMake a different choice\n";
				}
			}
			getline(cin, continu);

			while(continu != "n" && continu != "y")
			{
				whichGrid(gameType, gameArray, bigArray);
				cout << "Invalid entry\n";
				cout << "Game over!  Play again? y/n\n";
				getline(cin, continu);				
			}

		}

	gameType = menu();
	}

	system("CLS");
	cout << "Good bye!\n\n";
	system("pause");
	return(0);
}


//Splash
void splash()
{
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


int menu()
{
	string input;
	system("CLS");
	cout << "1. Human against human\n\n";
	cout << "2. Human against computer (smal grid)\n\n";
	cout << "3. Human against computer (big grid)\n\n";
	cout << "4. Quit\n\n";

	getline(cin,input);

	while (validateUserInput(4, input) != 0)
	{
		cout << "Please enter a valid choice\n";
		getline(cin,input);
	}

	return atoi(input.c_str());
}


//Function to get player's name
string user(int player)
{
	string name;
	int getInput;

	system("CLS");

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


//Display small or big grid based on the game type
void whichGrid(int gameType, string gameArray[], string bigArray[][12])
{
	if(gameType == 3)
		displayBigArray(bigArray);
	else
		displayGrid(gameArray);
}


void displayGrid(string gameArray[])
{
	system("CLS");
	cout << "      TIC-TAC-TOE\n\n";
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


//For game types 2 and 3 (Human against computer)
int pickSide()
{
	string input;
	system("CLS");

	cout << "Who goes first?\n\n";
	cout << " 1. Human\n";
	cout << " 2. Computer\n\n";

	getline(cin,input);

	while (validateUserInput(3, input) != 0)
	{
		cout << "Please enter a valid choice\n";
		getline(cin,input);
	}

	return atoi(input.c_str());
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
	return "error"; //in case something goes really wrong
}


bool checkPosition(string position, string gameArray[])
{

	int i = atoi(position.c_str());
	i = i - 1;

	if(gameArray[i] == position)
		{
			return true;
		}
	else
		{
			return false;
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


void switchPlayer(int &player, string &playerName, string player1, string player2, string &marker)
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


int validateUserInput(int type, string input)
{
	//1 = number validation
	//2 = name validation
	//3 = pick side
	//4 = menu

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
		case 4:
			if (input.find_first_not_of("1234") != string::npos || input.length() == 0)
				return(1);	
			else
				return(0);				
			break;			
	}
	return(0);
}


//Reset big array
void resetBigArray(string bigArray[][12])
{
    int i, j;

    //Fill all array values with pound signs
	for (i = 0; i < 15; ++i)
		for (j = 0; j < 12; ++j)
			 bigArray[i][j] = "#";

	//           |        |
	// 0     #   |  ####  |  ####
	// 1    ##   |     #  |     #
	// 2     #   |  ####  |   ###
	// 3     #   |  #     |     #
	// 4   ####  |  ####  |  ####
	//   ________|________|________
	//           |        |
	// 5   #  #  |  ####  |  #### 
	// 6   #  #  |  #     |  #    
	// 7   ####  |  ####  |  ####  
	// 8      #  |     #  |  #  # 
	// 9      #  |  ####  |  #### 
	//   ________|________|________
	//           |        |
	//10   ####  |  ####  |  ####         
	//11      #  |  #  #  |  #  #         
	//12      #  |  ####  |  ####         
	//13      #  |  #  #  |     #         
	//14      #  |  ####  |  ####      
	//   ________|________|________
	//     0123     4567     8901

	//Draw big numbers by clearing the pound sings, thus revealig the numbers
	//1
	bigArray[0][0]=" ";
	bigArray[0][1]=" ";
	bigArray[0][3]=" ";
	bigArray[1][0]=" ";
	bigArray[1][3]=" ";
	bigArray[2][0]=" ";
	bigArray[2][1]=" ";
	bigArray[2][3]=" ";
	bigArray[3][0]=" ";
	bigArray[3][1]=" ";
	bigArray[3][3]=" ";
	//2
	bigArray[1][4]=" ";
	bigArray[1][5]=" ";
	bigArray[1][6]=" ";
	bigArray[3][5]=" ";
	bigArray[3][6]=" ";
	bigArray[3][7]=" ";
	//3
	bigArray[1][8]=" ";
	bigArray[1][9]=" ";
	bigArray[1][10]=" ";
	bigArray[2][8]=" ";
	bigArray[3][8]=" ";
	bigArray[3][9]=" ";
	bigArray[3][10]=" ";
	//4
	bigArray[5][1]=" ";
	bigArray[5][2]=" ";
	bigArray[6][1]=" ";
	bigArray[6][2]=" ";
	bigArray[8][0]=" ";
	bigArray[8][1]=" ";
	bigArray[8][2]=" ";
	bigArray[9][0]=" ";
	bigArray[9][1]=" ";
	bigArray[9][2]=" ";
	//5
	bigArray[6][5]=" ";
	bigArray[6][6]=" ";
	bigArray[6][7]=" ";
	bigArray[8][4]=" ";
	bigArray[8][5]=" ";
	bigArray[8][6]=" ";	
	//6
	bigArray[6][9]=" ";
	bigArray[6][10]=" ";
	bigArray[6][11]=" ";
	bigArray[8][9]=" ";
	bigArray[8][10]=" ";	
	//7
	bigArray[11][0]=" ";
	bigArray[11][1]=" ";
	bigArray[11][2]=" ";
	bigArray[12][0]=" ";
	bigArray[12][1]=" ";
	bigArray[12][2]=" ";
	bigArray[13][0]=" ";
	bigArray[13][1]=" ";	
	bigArray[13][2]=" ";
	bigArray[14][0]=" ";
	bigArray[14][1]=" ";
	bigArray[14][2]=" ";	
	//8
	bigArray[11][5]=" ";
	bigArray[11][6]=" ";
	bigArray[13][5]=" ";
	bigArray[13][6]=" ";
	//9
	bigArray[11][9]=" ";
	bigArray[11][10]=" ";
	bigArray[13][8]=" ";
	bigArray[13][9]=" ";
	bigArray[13][10]=" ";
}


//Display big grid
void displayBigArray(string bigArray[][12])
{
	system("CLS");
    int i, j;

	cout << "         |        |\n";
	for (i = 0; i < 15; ++i)
	{	
		if(i == 5 || i == 10)
		{
			cout << " ________|________|________\n";
			cout << "         |        |\n   ";
		}
		else
			cout << "   ";
	    for (j = 0; j < 12; ++j)
	    {
		    cout << bigArray[i][j];
		    if(j == 3 || j == 7)
		    {
		       cout << "  |  ";
		    }
   		    if(j == 11)
		    {
		       cout << endl;
		    }
	    }
    }
    cout << "         |        |\n\n";
}


//Update big array with 'X' or 'O' on player's chosen position after each move
void updateBigArray(string choice, string marker, string bigArray[][12])
{

	int i = atoi(choice.c_str());
	int c, r;

	if(i == 1 || i == 2 || i == 3)
		r = 0;

	if(i == 4 || i == 5 || i == 6)
		r = 5;

	if(i == 7 || i == 8 || i == 9)
		r = 10;

	if(i == 1 || i == 4 || i == 7)
		c = 0;

	if(i == 2 || i == 5 || i == 8)
		c = 4;

	if(i == 3 || i == 6 || i == 9)
		c = 8;

	if(marker == "X")
	{
		// #  # 
		// #  # 
		//  ##  
		// #  # 
		// #  # 

		bigArray[r][c]="#";
		bigArray[r][c+3]="#";
		bigArray[r+1][c]="#";
		bigArray[r+1][c+3]="#";
		bigArray[r+2][c+1]="#";
		bigArray[r+2][c+2]="#";
		bigArray[r+3][c]="#";
		bigArray[r+3][c+3]="#";
		bigArray[r+4][c]="#";
		bigArray[r+4][c+3]="#";

		bigArray[r][c+1]=" ";
		bigArray[r][c+2]=" ";
		bigArray[r+1][c+1]=" ";
		bigArray[r+1][c+2]=" ";
		bigArray[r+2][c]=" ";
		bigArray[r+2][c+3]=" ";
		bigArray[r+3][c+1]=" ";
		bigArray[r+3][c+2]=" ";
		bigArray[r+4][c+1]=" ";
		bigArray[r+4][c+2]=" ";
	}
	else
	{
		//  ##  
		// #  # 
		// #  # 
		// #  # 
		//  ##  

		bigArray[r][c+1]="#";
		bigArray[r][c+2]="#";
		bigArray[r+1][c]="#";
		bigArray[r+1][c+3]="#";
		bigArray[r+2][c]="#";
		bigArray[r+2][c+3]="#";
		bigArray[r+3][c]="#";
		bigArray[r+3][c+3]="#";
		bigArray[r+4][c+1]="#";
		bigArray[r+4][c+2]="#";

		bigArray[r][c]=" ";
		bigArray[r][c+3]=" ";
		bigArray[r+1][c+1]=" ";
		bigArray[r+1][c+2]=" ";
		bigArray[r+2][c+1]=" ";
		bigArray[r+2][c+2]=" ";
		bigArray[r+3][c+1]=" ";
		bigArray[r+3][c+2]=" ";
		bigArray[r+4][c]=" ";
		bigArray[r+4][c+3]=" ";
	}
}


//Computer's algorithm (If computer goes first, it will use offensive moves, otherwise it will use defensive moves)
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
        for (int i = 0; i < 9; ++i)
        {
            if (gameArrayHidden[i] == 0)
            {
        		position = i+1;
				break;
            }
        }

        if(counter % 2 == 0) //If counter is even, computer has first move, thus use offensive moves
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

        //First offensive move (if computer goes first, randomly chose any of the below three moves)
        if(counter == 0)
        {
	       	unsigned seed = unsigned(time(0));
			srand(seed);
			int ii = (rand() % 3) + 1;

			switch(ii)
			{
				case 1:
			        if (gameArrayHidden[4] == 0)
			        	position = 5; //Center
					break;
				case 2:
					if (gameArrayHidden[0] == 0)
			        	position = 1; //Top left corner
					break;
				case 3:
					if (gameArrayHidden[2] == 0)
			        	position = 3; //Top right corner
					break;
			}
		}
    }

   	//Check if computer has two positions in one row/column/diagonal with a third position empty so it can win
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

    //Convert position from int to string and return it
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
