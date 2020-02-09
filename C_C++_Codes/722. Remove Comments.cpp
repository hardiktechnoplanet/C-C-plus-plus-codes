class Solution {
public:
    vector<string> removeComments(vector<string>& source) 
    {
        vector<string> result;
        //test case
        if(source.empty())
            return result;
        
        bool multiLineCommentMode=false;
        string str="";
        for(string s: source)
        {
            
            for(size_t i=0;i<s.length();++i)
            {
                //end of multiLineCommentMode
                if(multiLineCommentMode)
                {
                    if(s[i]=='*' && i<(s.length()-1) && s[i+1]=='/')
                    {
                        multiLineCommentMode=false;
                        i++; //to ignore the '/' in next iteration
                    }
                }
                else
                {
                    //single line comment
                    if(s[i]=='/' && i<(s.length()-1) && s[i+1]=='/')
                        break; //no need to process this line
                    
                    //start of multiLineCommentMode
                    else if(s[i]=='/' && i<(s.length()-1) && s[i+1]=='*')
                    {
                        multiLineCommentMode=true;
                        i++; //to ignore the '*' in next iteration
                    }
                    else
                        str+=s[i];
                }
            }
            if(str.length()>0 && !multiLineCommentMode)
            {
                result.push_back(str);
                str.clear();
            }
        }
        return result;
    }
};
