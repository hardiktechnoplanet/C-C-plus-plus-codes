/*First find out the extra number of open and closed brackets in the string. We have to 
remove these many brackets from the string to make it valid. Call the helper function. For
every open or close bracket encountered, it will first keep that and recuse and than it will
remove it and than make recursive calls*/

class Solution {
public:
    unordered_set<string> hash;
    void helperfn(string& s,int index,int leftremove,int rightremove,int pair,string temp)
    {
        // the pair variable is useful in the case when we remove an open bracket but kept the
        //closing bracket, in that case the pair value will be <0 and we can 
        //return in the base case below
        
        
        //base case (all the extra brackets are removed and string is completely parsed)
        if(leftremove==0&&rightremove==0&&pair==0&&index==s.length()){
            // cout<<temp<<endl;
            hash.insert(temp);
            return;
        }
        
        //base case (if we are tyring to remove more brackets then the required value)
        else if(leftremove<0||rightremove<0||pair<0){
            return;
        }
        
        //base case
        else if(index==s.length()){
            return;
        }
        
        //if open bracket is encountered, we have two choices, to keep it
        //or to remove it
        if(s[index]=='(')
        {
            //if we are removing it, decrement the leftremove
            helperfn(s,index+1,leftremove-1,rightremove,pair,temp);
            //if we are keeping it, increment the pair
            helperfn(s,index+1,leftremove,rightremove,pair+1,temp+'(');
        }
         //if close bracket is encountered, we have two choices, to keep it
        //or to remove it
        else if(s[index]==')')
        {
            helperfn(s,index+1,leftremove,rightremove-1,pair,temp);
            helperfn(s,index+1,leftremove,rightremove,pair-1,temp+')');
        }
        //if some other var
        else
        {
            helperfn(s,index+1,leftremove,rightremove,pair,temp+s[index]);
        }
    }
            
            
            
    
    vector<string> removeInvalidParentheses(string s) 
    {
        
        //test case
        if(s.length()==0)
        {
            string x;
            return vector<string> {x};
        }
        
        //variables to store extra brackets
        int leftremove=0;
        int rightremove=0;
        
        //find the extra open and close bracket that we have to remove
        for(auto c:s){
            if(c=='('){
                leftremove++;
            }
            else if(c==')'){
                if(leftremove>0){
                    leftremove--;
                }
                else{
                    rightremove++;
                }
            }
        }
        cout<<leftremove<<"  "<<rightremove<<endl;
        helperfn(s,0,leftremove,rightremove,0,"");
        return vector<string> (hash.begin(),hash.end());
    
    }
};
              
