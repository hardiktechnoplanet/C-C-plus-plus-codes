#include<bits/stdc++.h>
#include <string>
using namespace std;

//Backtracking is used. If the current letter in word string is found at the current index of board,
//save its value and mark it visited by replacing it with ' ' so that we don't use the same char more
//than once. Once the recursion call is returned, replace the element again.

//Time complexity: O(n*m) where n is the no of rows and m is the no of columns in matrix
//Space complexity: we are modifying the grid in place, but there is space complexity because 
//of the stack calls. So it will depend on the word string length.
bool dfsHelper(vector<vector<char>>& board, int count,int i,int j,string& word)
{
    //base case
    //if the whole word is found
    if(count==word.size())
    {
        return true;
    }
    
    //base case
    //if we are out of bound or the cell we are at does not contains the letter 
    //we are looking for
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[count])
    {
        return false;
    }
    
    //Mark the visited node, so that we don't use the same letter twice
    //We will replace the char with space, and while returing the call, we
    //will replace it again
    char temp=board[i][j];
    board[i][j]=' ';
    
    //recursion in all 4 directions
    bool found=dfsHelper(board,count+1,i+1,j,word) ||
        dfsHelper(board,count+1,i-1,j,word) ||
        dfsHelper(board,count+1,i,j+1,word) ||
        dfsHelper(board,count+1,i,j-1,word);
    
    //replace the element again
    board[i][j]=temp;
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    
    //test case
    if(board.empty())
    {
        return false;
    }
    
    //traverse through the board
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(dfsHelper(board,0,i,j,word))
                return true;
        }
    }
    return false;
}


int main()
{
	vector <vector<char> > board;
	vector <char> temp;
	temp.push_back('A');
	temp.push_back('B');
	temp.push_back('C');
	temp.push_back('D');
	board.push_back(temp);
	temp.clear();
	temp.push_back('E');
	temp.push_back('F');
	temp.push_back('G');
	temp.push_back('H');
	board.push_back(temp);
	
	string word="ABCCEH";
	if(exist(board, word)==true)
	cout<<"exists";
	else
	cout<<"not exists";
	
	return 0;
}
