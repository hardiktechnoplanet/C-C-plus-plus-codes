#include<iostream>
#include<stdio.h>
#define N 4
using namespace std;

//to print the final solution
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

//to check if we can put the queen at current row, column
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check the upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check the lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}

void place(int board[N][N] ,int row,int column)
{
	board[row][column]=1;
}

void remove(int board[N][N] ,int row,int column)
{
	board[row][column]=0;
}

int solveQueensHelper(int board[N][N], int column)
{
	static int count=0;
	//base case: if all the queens are placed
	if(column>=N)
	{
		count++;
	//	cout<<count<<endl;
	//	return true;
		printSolution(board);
		cout<<endl;
		cout<<endl;
	}
	else
	{
		//I need to place one queen in this column;
		//for each possible place in this column:
		for(int row=0;row<8;row++)
		{
			//choose 
			if(isSafe(board, row,column))
			{
				//choose if board thinks it is safe to place at this position
				place(board,row,column);
				
				//explore
				solveQueensHelper(board,column+1);
				
				//unchoose
				remove(board,row,column);
			}
		}
		//I have tried every possibility but no solution is found
		//printf("Solution does not exist");
		return count;
	}
}

int solveQueens()
{
	int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        //{0, 0, 0, 0},
        //{0, 0, 0, 0},
        //{0, 0, 0, 0},
       // {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    cout<<"count: "<<solveQueensHelper(board, 0);
}
int main()
{
	solveQueens();
	return 0;
}
