#include<iostream>
#include<stdio.h>
#define N 8
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

//it returns true if it finds a solution other wise false
bool solveQueensHelper(int board[N][N], int column)
{
	//base case: if all the queens are placed
	if(column>=N)
	{
		//cout<<board.toString()<<endl;
		return true;
	}
	else
	{
		//I need to place one queen in this column;
		//for each possible place in this column:
		for(int row=0;row<N;row++)
		{
			//for each row, choose, explore, and unchoose
			
			//choose 
			if(isSafe(board, row,column))
			{
				//choose if board thinks it is safe to place at this position
				place(board,row,column);
				
				//explore
				//if any call finds the solution then return true to all of 
				//the previous calls to stop the process because we want to 
				//have 1 solution only.
				 
				bool finished=solveQueensHelper(board,column+1);
				{
					if(finished)
					{
						return true;
					}
					
				}		
				//unchoose
				remove(board,row,column);
			}
		}
		//I have tried every possibility but no solution is found
		return false;
		
	}
}

bool solveQueens()
{
	int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if ( solveQueensHelper(board, 0) == false )
    {
      printf("Solution does not exist");
      return false;
    }
 
    printSolution(board);
    return true;
}
int main()
{
	solveQueens();
	return 0;
}
