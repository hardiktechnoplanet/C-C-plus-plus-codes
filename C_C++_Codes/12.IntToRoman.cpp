#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
# include <stdlib.h>
using namespace std;
string intToRoman(int x)
{
	string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
	string result=(M[x/1000] + C[(x%1000)/100] + X[(x%100)/10] + I[x%10]);
	return result;
}
int main()
{
	int x=3999;
	string result=intToRoman(x);
	cout<<result<<endl;
	return 0;
}
