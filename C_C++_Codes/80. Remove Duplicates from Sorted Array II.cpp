/*class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
    if(arr.size()<3)
	{
		return arr.size();
	}
	//check three continious element in the array, if three are the 
	//same, then we erase one of them. Repeat the process. 
	for(int i=0;i<arr.size()-2;i++)
	{
		if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2])
		{
			arr.erase(arr.begin()+i);
			i--;
		}
	}
	return arr.size();
        
    }
};*/

//Solution 2:Overwriting unwanted duplicates
//Time Complexity: O(N) since we process each element exactly once.
//Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& arr) 
    {
        //test case
        if(arr.size()==0)
            return 0;
        
        int j=1, count=1;
        for(size_t i=1;i<arr.size();++i)
        {
            //If the current element is a duplicate, increment the count.
            if(arr[i]==arr[i-1])
                count++;
            
            // Reset the count since we encountered a different element than the previous one
            else
                count=1;
            
            // For a count <= 2, we copy the element over thus
            // overwriting the element at index "j" in the array
            if(count<=2)
                arr[j++]=arr[i];
        }
        return j;
    }
};
