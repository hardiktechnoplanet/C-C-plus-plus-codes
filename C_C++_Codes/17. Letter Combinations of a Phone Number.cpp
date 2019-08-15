#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*Time complexity : O((3^N *4^M) where N is the number of digits in the input that maps to 3 letters 
(e.g. 2, 3, 4, 5, 6, 8) and M is the number of digits in the input that maps to 4 letters (e.g. 7, 9), 
and N+M is the total number digits in the input.

Space complexity :O(3^N *4^M) since we have to keep 3^N * 4^M solutions.*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        //to store the result
        vector<string> res;
        
        //test case
        if (digits.length()==0)
        {
            return res; 
        }
        
        vector<string> mapping({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string current="";
        helperFunction(digits,0,current,res,mapping);
        return res;
        
}
void helperFunction(string digits, int index, string& current, vector<string>& res, vector<string>& mapping)
{
    //base case
    if(index==digits.length())
    {
        res.push_back(current);
        return;
    }
    for(auto c: mapping[digits[index] - '0']){
        current.push_back(c);
        helperFunction(digits, index + 1, current, res, mapping);
        current.pop_back();
    }
}
};


