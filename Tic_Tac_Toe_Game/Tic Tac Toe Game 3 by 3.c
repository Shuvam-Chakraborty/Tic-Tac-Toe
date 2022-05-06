#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<MMsystem.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
char space=32;
char point=4;
char square[10]={'o','1','2','3','4','5','6','7','8','9'};// o is present here just to make the index same
/*
1	2	3
4	5	6
7	8	9
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int checkWin();//Function for checking winner
void drawBoard();//Function to draw the board
void displayRule();
void printline();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	//-----------------------------------------------------Background Color---------------------------------------------------------------//
	system("color 1f");
	//--------------------------------------------------------Variables------------------------------------------------------------------//
	int player=1, i, choice;				// player 1 and 2 are present, i is used to keep the track on the progress of the game, choice is used to take the choice from the user
	char mark;								// X or O
	char congrats=2;						// Congratulation message
	char name_player1[15],name_player2[15];	//Players names
	//-----------------------------------------------------Welcome Message--------------------------------------------------------------//
	printf("\n\t*** Welcome to the World of Tic Tac Toe!!! ***");
	Sleep(5000);// Waiting for a while
	system("cls");
	
	//------------------------------------------------Entering players details---------------------------------------------------------//
	printf("\n\t    *** Enter Player Details ***\n");
	printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\tEnter name of Player 1 : ");
	scanf("%s",name_player1);
	printf("\n\tEnter name of Player 2 : ");
	scanf("%s",name_player2);
	system("cls");
	
	
	///////-------------------------------------------*** Starting Game ***----------------------------------------------------///////
	
	printf("\n\tLet's Start the Game!!");
	printf("\n\n\n\tLoading...");
	Sleep(5000);	// Waiting for a while 
	system("cls");
	//-----------------------------------------------------Do While Loop-----------------------------------------------------------//
	do{
		system("cls");							//Clearing Screen
		printf("\n\t\t%c%c%c Tic Tac Toe %c%c%c\n\n",point,point,point,point,point,point);		//Printing Tic Tac Toe
		printline();		//Printing line
		printf("\n\t *** Players name and Marking Style ***\n\t----------------------------------------\n\t\t%s -> X\n\n\t\t%s -> O\n\n",name_player1,name_player2);
		printline();		//Printing line
		//-------------------------------------------------Display Rules----------------------------------------------------------//
		displayRule();
		printline();		//Printing line
		//-------------------------------------------------Display Board----------------------------------------------------------//
		drawBoard();
		printline();		//Printing line
		//-----------------------------------------Alternating players for each turn---------------------------------------------//
		player= (player%2) ? 1 : 2;
		//---------------------------------Taking player's choice where he/she wants to mark-------------------------------------//
		(player==1)?printf("\n\t%s, Enter your choice: ",name_player1):printf("\n\t%s, Enter your choice: ",name_player2);
		scanf("%d",&choice);
		printf("\n");
		printline();		//Printing line
		Sleep(500);
		//---------------------------------------Selecting mark type for each players--------------------------------------------//
		mark=(player==1)?'X':'O';
		//------------------------------------Entering the mark in the desired position-----------------------------------------//
		if(choice==1 && square[1]=='1')
			square[1]=mark;
		else if(choice==2 && square[2]=='2')
			square[2]=mark;
		else if(choice==3 && square[3]=='3')
			square[3]=mark;
		else if(choice==4 && square[4]=='4')
			square[4]=mark;
		else if(choice==5 && square[5]=='5')
			square[5]=mark;
		else if(choice==6 && square[6]=='6')
			square[6]=mark;
		else if(choice==7 && square[7]=='7')
			square[7]=mark;
		else if(choice==8 && square[8]=='8')
			square[8]=mark;
		else if(choice==9 && square[9]=='9')
			square[9]=mark;
		else
		{
			//---------------------------------If player chooses any invalid option-----------------------------------------//
			printf("\n\tInvalid option!!\n\n");
			printline();
			player--;// player is decremented because we want player should again play this turn as he/she has entered invalid input 
			getch();
		}
		//--------------------------After Every turn we will check whether any player wins or not--------------------------//
		i=checkWin();
		//----------------------Incrementing player so that the opponent can play in the next turn-------------------------// 
		player++;
	}while(i==-1);	// Condition For Continuing the game
	//------------------------------------Do While loop ends and we clears the output screen------------------------------//
	system("cls");
	
	
	///////-------------------------------------------*** Result Section ***-----------------------------------------///////
	
	//-----------------------------------------------We will draw the final Board-----------------------------------------//
	drawBoard();
	printline();		//Printing line
	//---------------------------------------------------Declaring Result------------------------------------------------//
	if(i==1)		//Winning Condition
	{
		system("color e4");		// Changing System Color
		//-------------------------------------------------Congratulating-----------------------------------------------//
		if(--player==1)
			printf("\n\t==> %s won!! %c Congratulations %c!!\n\n",name_player1,congrats,congrats);
		else
			printf("\n\t==> %s won!! %c Congratulations %c!!\n\n",name_player2,congrats,congrats);
		//-------------------------------------------Playing Music track(Win)-------------------------------------------//
		printline();		//Printing line
		PlaySound(TEXT("E:\\Codes\\Documents\\Games\\Music\\Win.wav"),NULL,SND_SYNC);
	}
	else			//Loosing Condition
	{
		system("color 70");		//Changing System Color
		printf("\n\t==> Game draw!!\n\n");	//Printing Game Draw
		printline();		//Printing line
		//------------------------------------------Playing Music track(Draw)-------------------------------------------//
		PlaySound(TEXT("E:\\Codes\\Documents\\Games\\Music\\Draw.wav"),NULL,SND_SYNC);
	}
	///////---------------------------------------------***Game Ends***-------------------------------------------///////
	getch();
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int checkWin()
{
	//------------------------------------Checking Row, Column, Diagonals For Match------------------------------------//
	if(square[1]==square[2] && square[2]==square[3])// 1	2	3
		return 1;
	else if(square[4]==square[5] && square[5]==square[6])// 4	5	6
		return 1;
	else if(square[7]==square[8] && square[8]==square[9])// 7	8	9
		return 1;
	else if(square[1]==square[4] && square[4]==square[7])// 1	4	7
		return 1;
	else if(square[2]==square[5] && square[5]==square[8])// 2	5	8
		return 1;
	else if(square[3]==square[6] && square[6]==square[9])// 3	6	9
		return 1;
	else if(square[1]==square[5] && square[5]==square[9])// 1	5	9
		return 1;
	else if(square[3]==square[5] && square[5]==square[7])// 3	5	7
		return 1;
	else if(square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9')		//Condition for Draw
		return 0;
	else			// Game is going on 
		return -1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void drawBoard()
{
	printf("\n\t  *** Tic Tac Toe Board ***  \n\t ---------------------------\n\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n",(square[1]=='X'||square[1]=='O')?square[1]:space,(square[2]=='X'||square[2]=='O')?square[2]:space,(square[3]=='X'||square[3]=='O')?square[3]:space);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n",(square[4]=='X'||square[4]=='O')?square[4]:space,(square[5]=='X'||square[5]=='O')?square[5]:space,(square[6]=='X'||square[6]=='O')?square[6]:space);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n",(square[7]=='X'||square[7]=='O')?square[7]:space,(square[8]=='X'||square[8]=='O')?square[8]:space,(square[9]=='X'||square[9]=='O')?square[9]:space);
	printf("\t\t     |     |     \n\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void displayRule()
{
	printf("\n\t     *** Board Positions ***\n\t    -------------------------\n\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  1  |  2  |  3  \n");
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  4  |  5  |  6  \n");
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  7  |  8  |  9  \n");
	printf("\t\t     |     |     \n");
	printf("\n\n\t%c Instruction : To mark in your desired position press respective key from keyboard\n\n",point);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void printline()
{
	int i;
	//-----------------------------------------Printing Line-----------------------------------------------//
	for(i=0;i<100;i++)
		printf("=");
	printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
