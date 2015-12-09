// Example program to update two-dimensional array with ascii art (Numbers)
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void resetBigArray(string bigArray[][12]);
void displayBigArray(string bigArray[][12]);
void updateBigArray(string choice, string marker, string bigArray[][12]);

int main()
{
    string bigArray[15][12];
    int counter = 0;
    int player = 1;
    string marker = "X";
	resetBigArray(bigArray);
	displayBigArray(bigArray);

	while(counter < 9)
	{
		string input;

		cout << "Make a move!\n";
		getline(cin,input);

		updateBigArray(input, marker, bigArray);
		
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

		system("CLS");
		displayBigArray(bigArray);
		counter++;
	}

	cout << "Good bye!\n";
	system("pause");
	return 0;
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

	int c, r, i = atoi(choice.c_str());

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
