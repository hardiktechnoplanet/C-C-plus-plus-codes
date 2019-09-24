// Firstly reverse every word in the string and than reverse the
// whole string. Finally, remove the extra spaces
class Solution {
public:
    string reverseWords(string s) 
    {
        //test case
        if(s.length()==0)
        {
            return s;
        }
        
        int start=0,end=s.length()-1,i=0,j=0,k=0;
        
        //remove space from the begining of the string
        while(s[start]== ' ')
        {
            start++;
        }
        //remove space from end of the string
        while(s[end]==' ')
        {
            end--;
        }
        
        i=start;
        j=i;
        //reverse every word in the string
        while(j<s.length())
        {
            //find individual words
            while(s[j]!=' ' && j<s.length())
            {
                j++;
            }
            k=j-1;
            
            //reverse individual words
            while(i<k)
            {
                char temp=s[i];
                s[i]=s[k];
                s[k]=temp;
                i++;
                k--;
            }
            
            //skip the extra spaces
            while(s[j]==' ' && j<s.length())
            {
                j++;
            }
            i=j;
        }
        
        s=s.substr(start,end-start+1);
        //reverse the string
        reverse(s.begin(),s.end());
        
        //remove extra spaces from the string
        return removeExtraSpace(s);
        
    }
    string removeExtraSpace(string& s)
    {
        int j=0;
        bool spaceFound=false;
        for(size_t i=0;i<s.length();++i)
        {
            if(s[i]!=' ')
            {
                s[j++]=s[i];
                spaceFound=false;
            }
            else
            {
                if(!spaceFound)
                {
                    s[j++]=s[i];
                    spaceFound=true;
                }
                
            }
        }
        s[j]='\0';
        return s;
    }
    
};

