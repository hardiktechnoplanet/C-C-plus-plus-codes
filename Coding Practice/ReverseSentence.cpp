/*reverse a sentence, ex: "who are you" should become "you are who"*/
#include<bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

void reverseSentence(string s)
{
	int len=s.length();
	cout<<"len: "<<len<<endl;
	char c=0;
	string temp;
	vector <string> vec;
	vector <string> :: reverse_iterator it;
	
	for(int i=0;i<len+1;i++)
	{
		c=s[i];
		cout<<"C: "<<c<<endl;
		
		//if we encounter ' ' or if are at last word of the string
		if(c==' ' || i==len)
		{
			cout<<"temp: "<<temp<<endl;
			vec.push_back(temp);
			vec.push_back(" ");
			temp.clear();
		}
		
		//add char to temp string to make a word
		else
		{
			temp +=c;
		}
	}
	
	//print the vector in reverse order
	for(it=vec.rbegin();it!=vec.rend();++it)
	{
		cout<<*it;
	}
}
int main()
{
	string s="who are you";
	reverseSentence(s);
	return 0;
}
