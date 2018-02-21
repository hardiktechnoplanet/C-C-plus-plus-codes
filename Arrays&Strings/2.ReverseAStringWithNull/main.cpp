#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(char *str,int len) {
char* end = str;
char* final=str;
char tmp;
if (str) {
 while (*end) { /* find end of the string */
 //++end;
 end++;
}
 --end; /* set one char back, since last char is null */
 cout<<"value at str"<<*str<<endl;
 cout<<"value at end"<<&end<<endl;
 
 /* swap characters from start of string with the end of the
 * string, until the pointers meet in middle. */
 //while (str < end) {
 while (str < end) {
 tmp = *str;
 *str++ = *end;
 *end-- = tmp;
 }
 }
 //for(int i=0;i<len;i++)
 cout<<endl;
 cout<<final;
 }

int main(int argc, char** argv) {
	char str[]="abcde";
	int len=sizeof(str);
	cout<<"len: "<<len<<endl;
	reverse(str,len);
	return 0;
}
