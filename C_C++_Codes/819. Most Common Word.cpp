//store the banned words in unordered_set so that we can find the word in O(1).
//traverse the paragraph string, make a valid word, convert it into lower case
//and check if it is in banned list. If not, increase its occurence in hash map.
//return the word with maximum occurence in hashmap
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        //put all the banned words in set so that we can have
        //O(1) access to find if the word is banned
        unordered_set<string> bannedList;
        
        for(auto word:banned)
        {
            bannedList.insert(word);
        }
        
        //make a hash map to store the words in paragrah along with
        //the frequencies 
        unordered_map<string,int> counts;
        string temp="";
        
        for(int i=0;i<paragraph.length();++i)
        {
            //check if the current char is valid('a' to 'z'), append it in temp
            //till one word is formed. Convert it to lower case.
            if(isValid(paragraph[i]))
            {
                temp+=tolower(paragraph[i]);
            }
            //once the word is formed, check if it is in the bannedList. If not,
            //increase it occurence in the hashmap.
            else
            {
                cout<<temp<<endl;
                if((temp.length()>0) && (bannedList.find(temp)==bannedList.end()))
                {
                    counts[temp]++;
                }
                temp.clear();
            }
            
        }
        //check for the last word in string paragraph
        if(temp!="")
        {
            counts[temp]++;
        }
        
        //variables to store the result
        int max=INT_MIN;
        string result;
        for(auto it:counts)
        {
            if(it.second>max)
            {
                max=it.second;
                result=it.first;
            }
        }
        return result;
        
        
    }
    bool isValid ( char c )
    {
        c = tolower( c );
        
        if ( c >= 'a' && c <= 'z' )
            return true;
        
        return false;
    }
};
