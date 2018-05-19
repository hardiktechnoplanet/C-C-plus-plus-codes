#include<bits/stdc++.h>
#include <algorithm>

using namespace std;

void print(vector<int>& initial)
{
	vector <int> ::iterator p;
	for(p=initial.begin();p!=initial.end();++p)
	cout<<*p<<"\t";
	cout<<endl;
}
vector <int> printDirectionsHelper(vector<int>& initial, vector<int>& target, vector<int>& emptySpace)
{
	//find the car that is present in target at the empty index of initial
    //num holds the car number at the loc
	int num=target.at(emptySpace.at(0));
		
	//find the loc of num car in initial
	int num_loc=find(initial.begin(),initial.end(),num)-initial.begin(); 
		
	cout<<"moving car "<<initial.at(num_loc)<<" to empty space ";
	cout<<"creating an empty space at location "<<num_loc<<" leading to the arrangement "<<"\t";
	//swap the car at num_loc and with the empty space loc in initial
	swap(initial.at(emptySpace.at(0)),initial.at(num_loc));
	//cout<<"moving car "<<initial.at(num_loc)<<" to empty space";
	
	emptySpace.clear();
		
	print(initial);

	return initial;
	
}
bool NonZero(int i)
{
	if (i!=0)
	return i;
}
void printDirections(vector<int>& initial, vector<int>& target)
{
	//test case
	if(initial.size()!=target.size())
	cout<<"invalid data"<<endl;

	//vector to store the position of empty spaces in initial and target 
	vector <int> emptySpace;
	//vector <int> :: iterator i;

	//repeat the process while the initial and target vectors are not same
	while(initial!=target)
	{
		//find the empty space location in initial and target and store it in emptySpace
		emptySpace.push_back(find(initial.begin(),initial.end(),0)-initial.begin());
		emptySpace.push_back(find(target.begin(),target.end(),0)-target.begin());

		//Now, there can be 2 cases, first case: the empty position in both the vectors are at
		//same location and second case: the empty space position is different. Make the first case 
		//similar to the second case by swaping the empty space location with any of the non empty space.
		 
		//if the empty space in initial is at same loc as in target, swap the empty loc in 
		//initial with any of the non empty loc in initial       
        if(emptySpace.at(0)==emptySpace.at(1))
        {
		//find a non zero value in the initial
		vector<int>::iterator nonZero = find_if (initial.begin(), initial.end(), NonZero);
		//find the position of nonZero car in the initial vector
		int nonZero_pos=find(initial.begin(),initial.end(),*nonZero)-initial.begin();
		//swap the empty space with the nonZero_pos in initial
		swap(initial.at(emptySpace.at(0)),initial.at(nonZero_pos));
		//update the location of empty space in emptySpace vector
		emptySpace.at(0)=nonZero_pos;
	}
	//if the empty space is at different locations in both the vectors, call the helper function
	printDirectionsHelper(initial,target,emptySpace);
}
}
int main()
{
	vector <int> initial;
	vector <int> target;
	initial.push_back(0);
	initial.push_back(4);
	initial.push_back(2);
	initial.push_back(5);
	initial.push_back(1);
	initial.push_back(3);
	

	target.push_back(1);
	target.push_back(0);
	target.push_back(5);
	target.push_back(3);
	target.push_back(2);
	target.push_back(4);
	
	printDirections(initial, target);
	return 0;
}
