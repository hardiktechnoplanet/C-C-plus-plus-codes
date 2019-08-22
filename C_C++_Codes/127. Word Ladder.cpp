//shortest transformation means BFS and BFS means queue
//Push the begin word in the queue and take a level variable. In the loop check the neighbors of queue element and
//push them in the queue and increase the level. Neighbors are the elements that are different by one letter and 
//helper function will find them. Once the queue front is the endword, return the level.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        //copy the wordList in a set. It is efficient to find and delete
        //in the set
        unordered_set<string> hash;
        for(size_t i=0;i<wordList.size();++i)
        {
            hash.insert(wordList[i]);
        }
        
        queue<string> q;
        //push the beginWord in the queue
        q.push(beginWord);
        //level will be our answer
        //we will increase the level after we move from one word to another
        int level=0;
        //to store the neighbors
        vector<string> neigh;
        
        //process the tree
        while(!q.empty())
        {
            int size=q.size();
            while(size>0)
            {
                string temp=q.front();
                q.pop();
                size--;
                
                if(temp==endWord)
                {
                    return level+1;
                }
                
                //find the neighbors
                neigh=helper(temp,hash);
                for(size_t i=0;i<neigh.size();++i)
                {
                    q.push(neigh[i]);
                    hash.erase(neigh[i]);
                }
            }
            level++;
        }
        return 0;
    }
    vector<string> helper(string& temp,unordered_set<string>& hash)
    {
        vector<string> ans;
        
        for(size_t i=0;i<temp.length();++i)
        {
            //save the original letter to replace at the end
            char old=temp[i];
            ////replace each letter by all the alphabets one by one to find the neighbors
            for(size_t j=0;j<26;++j)
            {
                temp[i]='a'+j;
                //if this neighbor is in our set, push it in ans vector
                if(hash.find(temp)!=hash.end())
                {
                    ans.push_back(temp);
                }
            }
            //get the original letter
            temp[i]=old;
            
        }
        return ans;
    }
};
