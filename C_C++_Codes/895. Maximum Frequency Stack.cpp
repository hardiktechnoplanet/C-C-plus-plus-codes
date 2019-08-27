/*push(int x): map the element (x) with frequency HashMap and update the maxfreq variable ( i.e. holds the maximum frequency till now ). setMap maintains a stack which contains all the elements with same frequency.
pop(): First get the maxfreq element from setMap and then decrement the frequency of the popped element. After popping, if the stack becomes empty then decrement the maxfreq.*/

class FreqStack {
    unordered_map<int,int> freqMap;
    unordered_map<int,stack<int>> setMap;
    int maxFreq=0;
    
public:
   
    void push(int x) 
    {
        //increase the frequency of x in freqMap
        int freq=freqMap[x]+1;
        freqMap[x]=freq;
        
        //get the maximum frequency
        if(freq>maxFreq)
        {
            maxFreq=freq;
        }
        //setMap will have all the elements with same frequency
        setMap[freq].push(x);
    }
    
    int pop() 
    {
        //get the max frequency element
        int top=setMap[maxFreq].top();
        setMap[maxFreq].pop();

        // Decrement the frequency of the popped element
        freqMap[top]--;
        

        // If whole list is poppped
        // then decrement the maxfreq
        if (setMap[maxFreq].size() == 0)
            maxFreq--;
        
        return top;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
