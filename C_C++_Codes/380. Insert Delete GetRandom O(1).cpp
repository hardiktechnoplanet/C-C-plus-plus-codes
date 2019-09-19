class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> hash;
    RandomizedSet() 
    {
        hash.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if(hash.find(val)==hash.end())
        {
            hash[val]=1;
            return true;
        }
        return false;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if(hash.find(val)!=hash.end())
        {
            hash.erase(val);
            return true;
        }
        return false;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        int size = hash.size();
        int random = rand() % size;
        unordered_map<int, int>::iterator it = hash.begin();
        //advance advances the iterator ‘it’ by n element positions
        advance(it, random);
        return it -> first;     
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
