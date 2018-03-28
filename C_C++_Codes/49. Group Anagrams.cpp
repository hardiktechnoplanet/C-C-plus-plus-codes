#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// utility function for printing anagram list
void printAnagram(unordered_map<string,
                              vector<string> >& store)
{
    unordered_map<string, vector<string> >::iterator it;
    for (it = store.begin(); it != store.end(); it++) {
        vector<string> temp_vec(it->second);
        int size = temp_vec.size();
        if (size > 1) {
            for (int i = 0; i < size; i++) {
                cout << temp_vec[i] << " ";
            }
            cout << "\n";
        }
    }
}
void groupAnagram(vector<string>& vec)
{
	unordered_map<string, vector<string> > store;
	for(int i=0;i<vec.size();i++)
	{
		string tempString(vec[i]);
		//sort the string
		sort(tempString.begin(),tempString.end());
		
		//check if the sorted string is present in the store
		//if it is not present
		if(store.find(tempString)==store.end())
		{
			vector<string> temp_vec;
			temp_vec.push_back(vec[i]);
			//store the key and the string in the store. Here key is the sorted string
			store.insert(make_pair(tempString,temp_vec));
		}
		//if it is present in store
		else
		{
			vector<string> temp_vec(store[tempString]);
			//push the string on the same key 
			temp_vec.push_back(vec[i]);
			store[tempString]=temp_vec;
		}
	}
	printAnagram(store);
}
int main()
{
	vector<string> arr;
	arr.push_back("geeksquiz");
	arr.push_back("geeksforgeeks");
	arr.push_back("forgeeksgeeks");
	arr.push_back("zuiqkeegs");
	arr.push_back("abcd");
	arr.push_back("cat");
	arr.push_back("tac");
	arr.push_back("act");
	groupAnagram(arr);
	return 0;
}
