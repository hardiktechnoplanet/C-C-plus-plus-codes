
// In a vector, store the last position of each char in string. Take 2 pointers, one will point
// to the start of substring and other will point to last index of this substring.
//Traverse through the string and update the end pointer. If we reach at the end index, this is last
//index of current substring. Save it in a vector and update the start pointer for the next substring.
class Solution {
public:
    vector<int> partitionLabels(string S) 
    {    
        vector<int> result;
        
        //test case
        if(S.length()==0)
        {
            return result;
        }
        
        //take an arry to store the last position of each letter in string
        vector<int> last(26);
        for(int i=0;i<S.length();++i)
        {
            last[S[i]-'a']=i;
        }
        
        //start represents starting index and end represents last index
        //of current substing
        int start=0, end=0;
        
        for(int i=0;i<S.length();++i)
        {
            //find the last position of current char
            end=max(end,last[S[i]-'a']);
            
            //if the loop reaches to the end position, this is breaking point
            //of the substing
            if(i==end)
            {
                result.push_back(i-start+1); //start+1 because string is 0 index based
                
                //next substring will start from i+1
                start=i+1;
            }
        }
        
        return result;
        
    }
};
