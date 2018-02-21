#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*this code prints all the possible subsets of a string*/
void findSubset(char* set,int len)
{
	for(int i=0;i<(1 << len);i++)
	{
		for(int j=0;j<len;j++)
		{
			if(i & (1 << j))
			{
				printf("%c",set[j]);
			}
		}
		printf("\n");
	}
}
int main(int argc, char** argv) {
	char set[]={'a','b','c'};
	int len=sizeof(set)/sizeof(set[0]);
	findSubset(set,len);
	return 0;
}
