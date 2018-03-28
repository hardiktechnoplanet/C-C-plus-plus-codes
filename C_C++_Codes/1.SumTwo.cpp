//Two Sum
/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include <iterator>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &array,int target)
{
	vector<int> result; //result vector is returned to the main loop
	map <int , int> intMap;
	map <int, int> :: iterator itr;
	/*Copy the array elements and indices to intMap*/
    for(int i=0;i<array.size();i++)
    {
    	intMap.insert(pair <int,int> (array[i],i));
	}
    cout<<"size: "<<intMap.size()<<endl;	
	for(int i=0;i<array.size();i++)
	{
		/*difference is target - array element, now, find the difference in the intMap
		if the value is present and if it is present at the index other than the array
		index we are currently at then push the 2 indices to the result vector.*/
		int difference=target-array[i];
		cout<<"difference: "<<difference<<endl;
		if(intMap.find(difference)!=intMap.end() && intMap[difference]!=i)
		{
			cout<<"i: "<<i<<" "<<"value: "<< intMap[difference]<<endl;
			result.push_back(intMap[difference]);
			result.push_back(i);
			return result;
		}
	}
	return result;
}
int main()
{
	vector <int> array={3,2,4};
	int target=6;
	twoSum(array,target);
	return 0;
}
