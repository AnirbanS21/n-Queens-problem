#include<iostream>
using namespace std;

int cnt;
char chessBoard[20][20];

bool checkValid(int row, int column)
{
	int i, j;
	for(i=0; i<column; i++)
	{
		if(chessBoard[row][i] == 'Q')
		{
			return false;
		}
	}
	for(i=row, j=column; i >= 0, j>=0; i--, j--)
	{
		if(chessBoard[i][j] == 'Q')
		{
			return false;
		}
	}
	for(i=row, j=column; i < cnt && j >= 0; i++, j--)
	{
		if(chessBoard[i][j] == 'Q')
		{
			return false;
		}
	}
	return true;
}

bool nQueen(int column)
{
	if(column >= cnt)
	{
		return true;
	}
	for(int i=0; i<cnt; i++)
	{
		if(checkValid(i, column))
		{
			chessBoard[i][column] = 'Q';
			if(nQueen(column+1))
			{
				return true;
			}
			chessBoard[i][column] = '-';
		}
	}
	return false;
}

int main()
{
	int i, j;
	cout << "\nEnter number of queens to be placed :";
	cin >> cnt;
	if(cnt==2||cnt==3)
		cout<<"No solution possible for "<<cnt<<" Queens!!!";
	else
	{
		for(i=0; i<cnt; i++)
		{
			for(j=0; j<cnt; j++)
			{
				chessBoard[i][j] = '-';
			}
		}
		nQueen(0);
		cout << "\nThe solution for " << cnt << " Queen's problem is :\n\n";
		for(i=0; i<cnt; i++)
		{
			for(j=0; j<cnt; j++)
			{
				cout << chessBoard[i][j] << "  ";
			}
			cout << "\n";
		}
	}
	cout<<"\n";
}

/*
OUTPUT

anirban@LAPTOP-LOQP78LI:/mnt/c/Users/anirb/Desktop$ g++ daa5.cpp
anirban@LAPTOP-LOQP78LI:/mnt/c/Users/anirb/Desktop$ ./a.out

Enter number of queens to be placed :8

The solution for 8 Queen's problem is :

Q  -  -  -  -  -  -  -
-  -  -  -  -  -  Q  -
-  -  -  -  Q  -  -  -
-  -  -  -  -  -  -  Q
-  Q  -  -  -  -  -  -
-  -  -  Q  -  -  -  -
-  -  -  -  -  Q  -  -
-  -  Q  -  -  -  -  -

*/
