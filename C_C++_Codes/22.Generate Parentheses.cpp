#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;
// GENERATE PARENTHESES
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

/*Algo: Instead of adding '(' or ')' every time, let's only add them when we know it will remain a valid sequence. 
We can do this by keeping track of the number of opening and closing brackets we have placed so far.
We can start an opening bracket if we still have one (of n) left to place. And we can start a closing 
bracket if it would not exceed the number of opening brackets.*/

/*Time Complexity : O({4^n}/{sqrt{n}}) 
Each valid sequence has at most n steps during the backtracking procedure.

Space Complexity : O({4^n}/{sqrt{n}}) 
*/

void dfs(string s, int opens, int closes, vector<string> &res) {
    if(!opens && !closes) res.push_back(s);
    if(opens) dfs(s + '(', opens - 1, closes, res);
    if(opens < closes) dfs(s + ')', opens, closes - 1, res);
}

vector<string> generateParenthesis(int n) {
        vector<string> res;
    dfs("", n, n, res);
    return res;
}

int main()
{
	int n=2;
	generateParenthesis(n);
	return 0;
}
