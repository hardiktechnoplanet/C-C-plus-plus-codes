/*take 3 maps for rows, columns, and boxes. Key value will be the row number, col number, and
box number and store the values. If for any particular key the value becomes>1 return false*/

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<int,char> rows[9],cols[9],boxes[9];
        
        //loop through the board
        for(size_t i=0;i<board.size();++i)
        {
            for(size_t j=0;j<board[0].size();++j)
            {
                if(board[i][j]!='.')
                {
                    char currentChar=board[i][j];
                    if(rows[i][currentChar]++>0 || cols[j][currentChar]++>0 || boxes[i/3*3+j/3][currentChar]++>0)
                        return false;
                }
            }
        }
        return true;
        
        
    }
};
*/

//https://www.youtube.com/watch?v=Pl7mMcBm2b8
//less space compexity than the above solution
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> seen;
        for (int i=0; i<9; ++i) 
        {
            for (int j=0; j<9; ++j) 
            {
                char number = board[i][j];
                if (number != '.')
                {
                    auto rowFlag=seen.insert(to_string(number) + " in row " + to_string(i));
                    auto colFlag=seen.insert(to_string(number) + " in column " + to_string(j));
                    auto boxFlag=seen.insert(to_string(number) + " in block " + to_string(i/3) + "-" + to_string(j/3));
                    
                    if(rowFlag.second==false || colFlag.second==false || boxFlag.second==false)
                        return false;
                }
            }
        }
        return true;
        
        
    }
};
