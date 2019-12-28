//https://www.youtube.com/watch?v=Wg8IiY1LbII
//Time Complexity:O(1) Amortized, Space Complexity: O(n)
class MyQueue {
public:
    
    /** Initialize your data structure here. */
    stack<int> pushStack,popStack;
    int front;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        //push the element to the push stack
        pushStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        //make sure that we don't have an empty popStack
        /* If the stack we can pop items from is empty then we need
        to populate it. All we do is put all items from the pushStack into the
        popStack.*/
        ensureThereAreItemsInPopStack();
        
        //if the popStack is still empty, it means that queue is empty, return -1
        if(!popStack.empty())
        {
            int frontElement=popStack.top();
            popStack.pop();
            return frontElement;
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() 
    {
        //Ensure that the pop stack has an item to peek
        ensureThereAreItemsInPopStack();

        //Peek the item if the queue is not empty
        if (!popStack.empty()) 
        {
            int frontElement=popStack.top();
            return frontElement;
        }

        //If queue is empty
        return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushStack.empty()&&popStack.empty();
        
    }
    
    void ensureThereAreItemsInPopStack()
    {
        if(popStack.empty())
        {
            while(!pushStack.empty())
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
