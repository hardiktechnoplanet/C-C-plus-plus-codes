/*this program reverses a string word by word*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

void stringSplit(string str)
{
	//vector of strings to save tokens
	vector <string> res;
	
	//stringstream class check1
	/*A stringstream associates a string object with a stream allowing us
	 to read from the string as if it were a stream*/
	stringstream check1(str);
	
	string intermediate;
	
	//tokenizing wrt to ' '
	while(getline(check1,intermediate, ' '))
	{
		res.push_back(intermediate);
	}
	
	//printing the res vector
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<endl;
	
}

int main()
{
  string str = "i love programming so much";
  stringSplit(str);
  return 0;
}
