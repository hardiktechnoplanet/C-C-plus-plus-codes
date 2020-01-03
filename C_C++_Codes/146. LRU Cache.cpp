class LRUCache {
public:
    
    int maxSpace;
    list<int> dq; //doubly linked list
    unordered_map<int,int> mem;
    unordered_map<int,list<int>::iterator> index;
    LRUCache(int capacity) 
    {
        maxSpace=capacity;
    }
    
    int get(int key) 
    {
        int result;
        if(mem.find(key)==mem.end())
        {
            return -1;
        }
        //result=mem[key];
        
        //put this element in the front
        dq.erase(index[key]);
        //update reference
        dq.push_front(key);
        index[key]=dq.begin();
        result=mem[key];
        
        return result;
    }
    
    void put(int key, int value) 
    {
        //mem[key]=value;
        //if key is not present in the cache
        if(mem.find(key)==mem.end())
        {
            //if the cache is full
            if(dq.size()==maxSpace)
            {
                //delete the LRU element
                int back=dq.back();
                //pop the back element
                dq.pop_back();
                //erase the back element
                mem.erase(back);
                
            }
        }
        // present in cache 
        else
        {
            dq.erase(index[key]);
        }

        // update reference 
        dq.push_front(key); 
        mem[key] = value;
        index[key]=dq.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 
 /////////////////////////////////////////////////////////////////////
 
 class LRUCache {
public:
    
    int maxSpace;
    list<pair<int, int>> dq; //doubly linked list
    //unordered_map<int,int> mem;
    unordered_map<int,list<pair<int, int>>::iterator> mem;
    LRUCache(int capacity) 
    {
        maxSpace=capacity;
    }
    
    int get(int key) 
    {
        int result;
        if(mem.find(key)==mem.end())
        {
            return -1;
        }
        //result=mem[key];
        
        //put this element in the front
        //list<pair<int, int>>::iterator iter = mem[key];
        //auto itr=*mem[key];
        
        //deference to get the value
        result=mem[key]->second;
        
        //result=itr.second;
        dq.erase(mem[key]);
        //update reference
        dq.push_front({key,result});
        mem[key]=dq.begin();
        //result=mem[key];
        
        return result;
    }
    
    void put(int key, int value) 
    {
        //mem[key]=value;
        //if key is not present in the cache
        if(mem.find(key)==mem.end())
        {
            //if the cache is full
            if(dq.size()==maxSpace)
            {
                //delete the LRU element
                auto back=dq.back();
                //pop the back element
                dq.pop_back();
                //erase the back element
                mem.erase(back.first);
                
            }
        }
        // present in cache 
        else
        {
            dq.erase(mem[key]);
        }

        // update reference 
        dq.push_front({key,value}); 
        mem[key] = dq.begin();
        //index[key]=dq.begin();
        
    }
                      
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
