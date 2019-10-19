/*upper_bound() returns an iterator pointing to the first element in the 
range [first, last) that is greater than value*/

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string,map<int,string>> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        hash[key][timestamp]=value;
        
    }
    
    string get(string key, int timestamp) 
    {
        auto find = hash[key].upper_bound(timestamp);
        if(find == hash[key].begin()) return "";
        find--;
        return find->second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
