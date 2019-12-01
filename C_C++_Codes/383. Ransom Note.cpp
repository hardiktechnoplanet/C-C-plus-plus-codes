class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int> hash;
        for(size_t i=0;i<magazine.length();++i)
        {
            hash[magazine[i]]++;
        }
        
        for(size_t i=0;i<ransomNote.length();++i)
        {
            if(hash[ransomNote[i]]>0)
            {
                hash[ransomNote[i]]--;
            }
            else
                return false;
        }
        return true;
    }
};
