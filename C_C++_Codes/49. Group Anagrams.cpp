/*Time Complexity: O(NKlogK), where N is the length of strs, and K is the maximum length of a string in strs. 
The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(KlogK) time.

Space Complexity: O(NK), the total information content stored in result.*/
/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mem;
        
        for(size_t i=0;i<strs.size();++i)
        {
            string temp=strs[i];
            //sort the string, the sorted string will be our key
            sort(temp.begin(),temp.end());
            
            mem[temp].push_back(strs[i]);
        }
        
        for(auto x: mem)
            result.push_back(x.second);
        
        return result;
        
    }
};*/

/*Time Complexity: O(NK), where N is the length of strs, and K is the maximum length of a string in strs. 
Counting each string is linear in the size of the string, and we count every string.

Space Complexity: O(NK), the total information content stored in anagrams.*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            //cout<<counter[c]<<"\t"<< c + 'a'<<endl;
            t += string(counter[c], c + 'a');
            //cout<<t<<endl;
        }
          //cout<<t<<endl;
        return t;
    }
};
