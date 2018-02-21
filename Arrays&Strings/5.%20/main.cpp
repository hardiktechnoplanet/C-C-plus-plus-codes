#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code will put %20 in place of ' ' in a string*/
void space(char str[],int length)
{
	char *final=str;
	int spacecount=0, newlength, i=0;
	for ( i=0;i<length;i++)
	{
		if(str[i]==' ')
		{
			spacecount++;
		}
	}
	newlength=length+spacecount*2;
	str[newlength]='\0';
	for(i=length-1;i>=0;i--)
	{
		if(str[i]==' ')
		{
			str[newlength-1]='0';
            str[newlength-2]='2';
			str[newlength-3]='%';	
			newlength=newlength-3;		
		}
		else{
		
		str[newlength-1]=str[i];
		newlength=newlength-1;
	}}
	cout<<final;
}
int main(int argc, char** argv) {
	char str[]="ha dik";
	int length=sizeof(str);
	space(str,length);
	return 0;
}
