//Time Complexity : O(N – K) * K
//N : length of string s.
//K : total length of list words if all the words are concatenated. If words : [“ab”, “cd”] then K = 4.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        //resultant vector that stores indices
        vector<int> result;
        if(s.length()==0 || words.size()==0)
        {
            return result;
        }
        
        //number of char in each word in words
        int size_word=words[0].size();
        //number of words present in words
        int word_count=words.size();
        //total char present in words
        int size_L=size_word*word_count;
        
        //test case
        //if total chars in words is > s length
        if(size_L>s.length())
        {
            return result;
        }
           
        //unordered map to store word present in words along with
        //occurrences
        unordered_map<string,int> hash_map;
        for(size_t i=0;i<word_count;++i)
        {
            hash_map[words[i]]++;
        }
        
        for(size_t i=0;i<=s.length()-size_L;++i)
        {
            unordered_map<string,int> temp_hash_map(hash_map);
            int j=i,count=word_count;
            
            //traverse through the substring
            while(j<i+size_L)
            {
                //extract the word
                string word=s.substr(j,size_word);
                //if word is not found, break
                if(hash_map.find(word)==hash_map.end() || temp_hash_map[word]==0)
                {
                    break;
                }
                //decrement the count of the word in hash_map
                else
                {
                    temp_hash_map[word]--;
                    count--;
                }
                j+=size_word;
            }
            // Store the starting index of that substring when all the words in the list are in substring 
        if (count == 0) 
            result.push_back(i);  
        }
        return result;
    }
};
