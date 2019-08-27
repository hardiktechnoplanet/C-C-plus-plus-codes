class MinStack {

public:
    /** initialize your data structure here. */
    vector<int> s;
    int min;
    MinStack() 
    {
        min=INT_MAX;    
    }
    void push(int x) 
    {
        s.push_back(x);
        //update the min variable
        if(x<min)
        {
            min=x;
        }
    }
    
    void pop() 
    {
        //check if the last element is the min element
        //if true, update the min element with any of the 
        //elements, we will find the true min in the for
        //loop below
        if (top() == min) {
            if (s.size() == 1) {
                min = INT_MAX;
            } else 
            {
                min = s[0];
            }
            //find the min element (last element will be gone
            //so, check untill size()-1)
            for (size_t i = 0; i < s.size() - 1; ++i) {
                if (s[i] < min) {
                    min = s[i];
                }
            }
        }
        s.pop_back();
    }
    
    int top() 
    {
        //get the last element from the vector
        return s[s.size()-1];
    }
    
    int getMin() {
       return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
