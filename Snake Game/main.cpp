#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>

using namespace std;

bool gameOver ;
const int width = 25;
const int height = 25;





int x,y; //coordinates of snake head
//Tail making
int tailX[899],tailY[899];

int nTail;



int fruitX,fruitY; // cordinates of fruit to be randomly generated

int Score;

enum hDirection{ STOP = 0,LEFT,RIGHT,UP,DOWN};
hDirection dir;


void ClearScreen()
{	
COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}



void Setup()
{
	gameOver = false;
	dir = STOP;
	
	x = width/2;
	y = height/2;
	fruitX = rand() %(width+1);
	fruitY = rand() %(height+1);
	Score =0;
	
}


void Draw()
{
	ClearScreen();

	
	
	for(int i = 0;i<width;i++)
	cout<<"##";
	
	cout<<endl;
	
	for(int i =0;i<height;i++)
	{
		for(int j = 0;j<width;j++)
		{
			
			if(j==0||j==width-1)
			cout<<"#";
			if(i == y && j ==x)
			cout<<"0";
			else if(i == fruitY && j==fruitX)
			cout<<"@";
			else 
			{
				bool print = false;

				for(int k =0;k<nTail;k++)
				{
					if(tailX[k] == j && tailY[k] == i)
					{
						cout<<"o";
						print  = false;
					}
					
				}
				if(!print) 
					cout<<" ";
			}
			if(j!=0||j!=width)
			cout<<" ";
			
		}
		cout<<endl;
	}
	
	
	for(int i = 0;i<width;i++)
	cout<<"##";
	
	cout<<endl;
	cout<<"score"<<Score;
	
	
	
	
}


void Input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
			dir = LEFT;
			break;
			case 'd':
			dir = RIGHT;
			break;
			case 's':
			dir = DOWN;
			break;
			case 'w':
			dir = UP;
			break;
			case 'x':
			gameOver = true;
		}
	}
	
	
	
	
}


void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	
	tailX[0] = x;
	tailY[0] = y;
	
	int prev2X,prev2Y;
	
	for(int i =1;i<nTail;i++)
	{
		
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		
	
	}
	
	
	
	
	switch(dir)
	{
		case LEFT:
		x--;
		break;
		case RIGHT:
		x++;
		break;
		case UP:
		y--;
		break;
		case DOWN:
		y++;
		break;
	
		default:
		break;
		
	}
	
	
	
	//if(x>width|| x<0 ||y<0 ||y>height)
	//	gameOver = true;
		
		if(x>=width) 
		x =0;
		else if(x<0)
		x = width -1;
		
		if(y>=height)
		y = 1;
		else if(y<=0)
		y = height-1;
		
	for(int i =0;i<nTail;i++)
	{
		
		if(tailX[i] ==x && tailY[i] ==y)
		gameOver = true;
	}
	if(x == fruitX && y ==fruitY)
	{
		Score = Score +1;
	fruitX = rand() %(width+1);
	fruitY = rand() %(height+1);
	nTail++;
	}
	
}


int main()
{
	
	Setup();
	
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10);
				
	}

}
