class Solution {
public:
    string getPermutation(int n, int k) 
    {
        //make the input string
        string input="";
        for(size_t i=1;i<=n;++i)
        {
            input+=to_string(i);
        }
        cout<<input;
        string result="";
        string chosen="";
        priority_queue<int> heap;
        int count=0;
        helper(input,chosen,result,k,count);
        
        return result;
    }
    
    void helper(string& input, string& chosen,string& result,int k,int& count)
    {
        //base case
        if(input.length()==0)
        {
            //cout<<chosen<<endl;
            count++;
            if(count==k)
            {
                result=chosen;
            }
            //cout<<chosen<<endl;
            //permuteRes.push_back(stoi(chosen));
            return;
        }
        else if(count<k)
        {
            for(size_t i=0;i<input.length();++i)
            {
                //choose
                char c=input[i];
                chosen+=c;
                input.erase(i,1);
                
                //explore
                helper(input,chosen,result,k,count);
                
                //unchoose
                chosen.erase(chosen.length()-1);
                input.insert(i,1,c);
            }
        }
            
    }  
 
};
