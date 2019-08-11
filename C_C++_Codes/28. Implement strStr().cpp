#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int strStr(string haystack,string needle)
{
	int hSize=haystack.size();
    int nSize=needle.size();    
    if(nSize==0){
    	return 0;
    }
        
    // instead of using brute force, we will run the nested for loop only when the present char in both
    //the strings are same
	for(size_t i=0;i<hSize;++i)
    {
        int j=0;
        if(haystack[i]==needle[j])
        {
            for(;j<nSize;++j)
            {
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==nSize)
                return i;
        }
    }
    return -1;
}
int main()
{
	string haystack="""";
	string needle="";
	cout<<"i: "<<strStr(haystack,needle)<<endl;
	return 0;
}
