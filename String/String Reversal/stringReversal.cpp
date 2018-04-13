/*this program reverses a string word by word*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

void stringReversal(char s[],int len)
{
	vector <string> res; // to store the reversed string
	char c;
	bool flag=false;
	cout<<"len"<<len<<endl;
	string choosen;
	for(int i=len-1;i>=0;i--)
	{
		/*base case: if a space is encountered, it means that one word is complete and
		pointer is moving to next word. So far we have reversed a word and now we can push
		it to the res vector and clear the choosen string*/
		
		if(s[i]==' ')
		{
			res.push_back(choosen);
			res.push_back(" ");
			cout<<"hello"<<endl;
			choosen.clear();
		}
		/*take one char at a time and add to the choosen string. flag is used for the last word
		to be reversed */
		else
		{
			cout<<"s[i]: "<<s[i]<<endl;
			c =s[i];
			choosen +=c;
			cout<<"c: "<<c<<endl;
			cout<<"choosen: "<<choosen<<endl;
			cout<<"i: "<<i<<endl;
			cout<<endl;
			if(i==0)
			flag=true;
		}
		
	}
	/*if flag is tree it implies that we are at the last letter of the last word to be reversed*/ 
	if(flag==true)
	res.push_back(choosen);
	
	/*print the res vector*/
	cout<<"reversed string: ";
	for(int i=0;i<res.size();i++)
	cout<<res[i];
}



int main()
{
  char s[] = "i love programming so much";
  int len=strlen(s);
  stringReversal(s,len);
  //printf("%s", s);
  //getchar();
  return 0;
}
