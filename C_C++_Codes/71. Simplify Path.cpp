class Solution {
public:
    string simplifyPath(string path) 
    {   
        //test case
        if(path.length()==0)
            return "";
        
        string result="",word="";
        vector<string> st;
        
        //split the string with '/' as delimeter
        stringstream str(path);
        while(getline(str,word,'/'))
        {
            if(word=="." || word=="")
                continue;
            //move up a directory
            else if(word=="..")
            {
                if(!st.empty())
                    st.pop_back();
            }
            else
                st.push_back(word);
        }
        
        if(st.empty())
            return "/";
        
        for(size_t i=0;i<st.size();++i)
        {
            result=result+'/'+st[i];
        }
        return result;
    }
};
