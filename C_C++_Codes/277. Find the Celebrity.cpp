/*Take the first element as celebrity. Traverse through 1 to n elements and find the last
element that can be celebrity. Now, traverse again to check if this celebrity is actually 
a celebrity.*/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) 
    {
        //lets take 0 as celebrity
        int celebrity=0;
        
        //now find the last element in n elements that can be the celebrity
        for(size_t i=1;i<n;++i)
        {
            if(knows(i,celebrity))
                continue;
            else
                celebrity=i;
        }
        
        //now check if the celebrity is actually celebrity
        for(size_t i=0;i<n;++i)
        {
            if(i!=celebrity && (knows(celebrity,i) || !knows(i,celebrity)))
                return -1;
        }
        return celebrity;
    }
};
