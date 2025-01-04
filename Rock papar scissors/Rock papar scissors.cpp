#include <iostream>
#include <string>
#include <Windows.h>
using namespace std; 
enum choices { stone = 1, paper = 2, scissor = 3 };









// This function will read the user choice 
int readChoice()
{
	int choice; 
	cout << "Enter your choice : [1] stone, [2] paper, [3] scissor  ==> "; cin >> choice; 
	cout << "\n"; 
	return choice; 
}

//function to generate a random number 
int randomNum(int from, int to) { return rand() % (to - from + 1) + from; }

// function to convert the enum to string
string stringChoice(choices choice)
{
	if (choice == stone) return "stone";
	else if (choice == paper) return "paper";
	else return "scissor";
}

void headerGame()
{
	cout << " ====================================================================" << endl;
	cout << "|                                                                    |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "|             R O C K     P A P E R     S C I S S O R                |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "|                                                                    |" << endl;
	cout << " ====================================================================" << endl;
	cout << "\n\n" << endl; 
}
void lines()
{
	cout << "\n\n\n"; 
}

//this function will generate the computer choice ; 
choices compChoice()
{
	int choice = randomNum(1, 3);
	switch (choice)
	{
	case stone : 
		return stone; 
	case paper :
		return paper;
	case scissor :
		return scissor;
	default:
		break;
	}
}
// function to decide the player result : 
choices playerChoice(int choice)
{
	switch (choice)
	{
	case stone:
		return stone;
	case paper:
		return paper;
	case scissor:
		return scissor;
	default:
		break;
	}
}

//I. I need to devide the project into small functions 
string roundResult(choices comp, choices play)
{
	if (comp == play)	return "No winner";
	else if (comp == stone && play == scissor || comp == scissor && play == paper || comp == paper && play == stone) return "Computer";
	else return "Player";
	
}

// round function
string roundGame(int roundNumber)
{
	lines(); 
	cout << "ROUND [" << roundNumber << "] begins : \n\n" << endl;
	choices computer = compChoice();
	choices player = playerChoice(readChoice());
	cout << "__________ROUND [" << roundNumber << "] __________\n" << endl; 
	cout << "Player choice : " << stringChoice(player) << endl; 
	cout << "Computer choice : " << stringChoice(computer) << endl;
	string result = roundResult(computer, player);
	
	cout << "Round winner : [" << result << "]" << endl;
	cout << "______________________________" << endl; 
	return result; 
}






void gameResult(int p, int c, int rounds, int draw) 
{ 
	string winner; 
	cout << "              ___________________________________________________________________________________                         \n" << endl;
	if (p > c)
	{ 
		winner = "Player";
		cout << "                                      C O N G R A J U L A T I O N S 🎉🎉🎉                                            \n" << endl; 
	}
	else
	{
		c > p ? winner = "Computer" : winner =  "No Winner";
		cout << "                                         G A M E            O V E R                                                     \n" << endl; 
	} 
	cout << "              ____________________________________________________________________________________                         \n" << endl;


	cout << "              __________________________[G A M E   R E S U L T S ] _______________________________                        \n" << endl; 
	
	cout << "              Game Rounds            : " << rounds << endl; 
	cout << "              Player won times       : " << p << endl; 
	cout << "              Computer won times     : " << c << endl; 
	cout << "              Draw times             : " << draw << endl; 
	cout << "              Final winner           : " << winner << endl; 
	

	cout << "\n              _____________________________________________________________________________________                         \n" << endl;
}








int main()
{
	srand((unsigned)time(NULL));

	int roundNums;
	string yesOrNo = "yes";

	while(yesOrNo != "no")
	{
		system("cls"); system("color 0F");
		headerGame();
		cout << "How many rounds do you want to play (1 to 10) ? : "; cin >> roundNums;
		int rounds = roundNums;
		int player = 0;
		int computer = 0;
		int draw = 0;
		while (rounds > 0)
		{
			string dec = roundGame(rounds);
			if (dec == "Player")
			{
				system("color 2F");
				player++;
			}
			else if (dec == "Computer")
			{
				system("color 4F"); 
				Beep(100, 300);
				computer++;
			}
			else {
				system("color 6F");
				draw++;
			}
			rounds--;
		}

		gameResult(player, computer, roundNums, draw); 
		lines(); 

		cout << "Would you like to play again ? : "; cin >> yesOrNo;
	}





}