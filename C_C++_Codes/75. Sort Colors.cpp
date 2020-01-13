#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int smaller=0, equal=0, larger=nums.size();
        while(equal<larger)
        {
            if(nums[equal]<1)
                swap(nums[smaller++],nums[equal++]);
            else if(nums[equal]==1)
                equal++;
            else
                swap(nums[equal],nums[--larger]);
        }
    }
};
////////////////////////////////////////////////////////////////////////////////

/*We go through each element one by one, if we find 0, we swap it to the red flag pointer 
and increment the pointer. If we find Blue flag, we swap it to the blue flag pointer and 
decrement it. Once it has been swapped, we need to decrease the array size by one so that 
the sorted blue flags won’t be visited again.*/
void sortColors(vector<int>& nums)
{
	int n=nums.size();
	int i=0,j=0;
	
	for(i=0;i<n;i++)
	{
		if(nums[i]==0)
		swap(nums[i],nums[j++]);
		
		else if(nums[i]==2)
		{
			cout<<"n: "<<--n<<endl;
			swap(nums[i--],nums[--n]);
		}
		
	}
	
	//print the sorted vector
	vector <int> :: iterator it;
	for(it=nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<"\t";
	}
}
int main()
{
    vector <int> nums;
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
	
	sortColors(nums);
	return 0;
}
