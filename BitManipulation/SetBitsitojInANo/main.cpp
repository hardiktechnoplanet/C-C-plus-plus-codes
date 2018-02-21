#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code replaces the bits present from i to j in a number n with m*/ 
int SetNo (int n,int m,int i, int j)
{
	int max=~0;
	int left=max - ((1 << j)-1);
	cout<<"left: "<<left<<endl;
	int right= ((1 << i)-1);
	cout<<"right: "<<right<<endl;
	int mask=left|right;
	cout<<"mask: "<<mask<<endl;
	return ((n & mask)|(m << i));
}
int main(int argc, char** argv) {
	int n=1024;
	int m=21;
	int i=2,j=6;
	cout<<"result: "<<SetNo(n,m,i,j)<<endl;
	return 0;
}
