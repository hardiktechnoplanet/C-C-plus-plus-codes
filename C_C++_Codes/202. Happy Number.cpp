/*Solution 1: Repeatedly do sum of squares of digits. While doing so,keep track of visited 
numbers using a hash. If we reach 1, we return true. Else if we reach a visited 
a number, we return false.
https://www.geeksforgeeks.org/happy-numbers/
*/

class Solution {
public:
    bool isHappy(int n) 
    {
        // A set to store numbers during 
        // repeated square sum process 
        set<int> s;
        s.insert(n);
        
        // Keep replacing n with sum of 
        // squares of digits until we either 
        // reach 1 or we endup in a cycle 
        while(1)
        {
            // Number is Happy if we reach 1
            if(n==1)
                return true;
            
            // Replace n with sum of squares of digits
            n=sumDigitSq(n);
            
            // If n is already visited, a cycle 
            // is formed, means not Happy
            if(s.find(n)!=s.end())
                return false;
            
            // Mark n as visited
            s.insert(n);
        }
        return false;
        
    }
    
    // Returns sum of squares of digits 
    int sumDigitSq(int n)
    {
        int sq=0;
        while(n)
        {
            int digit=n%10;
            sq+=digit*digit;
            n=n/10;
        }
        return sq;
    }
};


/*Solution 2: We can solve this problem without using extra space if we treat
every number as a node and replacement by square sum digit as a link, then 
this problem is same as finding a loop in a linklist : So from above link, 
we will keep two number slow and fast both initialize from given number, slow 
is replaced one step at a time and fast is replaced two steps at a time. If they 
meet at 1, then the given number is Happy Number otherwise not.
https://www.geeksforgeeks.org/happy-number/
*/
/*
class Solution {
public:
    bool isHappy(int n) 
    {
        int slow, fast; 
  
        //    initialize slow and fast by n 
        slow = fast = n; 
        do
        { 
            //move slow number by one iteration 
            slow = sumDigitSq(slow); 

            //move fast number by two iteration 
            fast = sumDigitSq(sumDigitSq(fast)); 

        } 
        while (slow != fast); 

        //if both number meet at 1, then return true 
        return (slow == 1); 

    }

        // Returns sum of squares of digits 
        int sumDigitSq(int n)
        {
            int sq=0;
            while(n)
            {
                int digit=n%10;
                sq+=digit*digit;
                n=n/10;
            }
            return sq;
    }
};
*/
