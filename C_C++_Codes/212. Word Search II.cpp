
//Backtracking is used. If the current letter in word string is found at the current index of board,
//save its value and mark it visited by replacing it with ' ' so that we don't use the same char more
//than once. Once the recursion call is returned, replace the element again.

//Time complexity: O(n*m) where n is the no of rows and m is the no of columns in matrix
//Space complexity: we are modifying the grid in place, but there is space complexity because 
//of the stack calls. So it will depend on the word string length.

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> result;
        //test case
        if(board.empty())
        {
            return result;
        }
        outerloop:
        while(!words.empty())
        {
            string word=words[words.size()-1];
            words.pop_back();
            cout<<"size: "<<words.size()<<endl;
            string temp=word;
            cout<<"temp: "<<temp<<endl;
            //traverse through the board
            int i;
            for(i=0;i<board.size();i++)
            {
                for(int j=0;j<board[0].size();j++)
                {
                    if(dfsHelper(board,0,i,j,word))
                    {
                        
                        //if(std::find(result.begin(), result.end(), temp) == result.end())
                        {
                            result.push_back(temp);
                            goto outerloop;   
                        }
                        //break;
                    }
                }
            }
        }
        return result;
    }
    
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
};
        
   
