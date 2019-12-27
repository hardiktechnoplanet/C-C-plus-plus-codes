/*Traverse through the string, put each element in the stack, if the 
next element in the string is < stack top, remove the element at the
top of the stack.
Example: string 1432219
Stack: 1 4
Next element: 3, now, we can have 14 or 13, 13 is <14, remove stack top.

Count the number of elements that we have removed. If the count<k and
string traversal is complete, it means that rest of the string is in
increasing order. In this case remove the k-count elements from end of 
the string.
Remove 0's from front of the string.

Time and Space Complexity: O(n)
https://www.youtube.com/watch?v=vbM41Zql228&t=589s
Check the leetcode solution as well
*/
class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        //test case
        if(num.length()==0 || num.length()==k)
            return "0";
        
        stack<int> s;
           
        //traverse through the string, put the elements in the stack
        //if the next element in string <top of stack, pop the stack top
        for(size_t i=0;i<num.length();++i)
        {
            while(s.size()>0 && k>0 && s.top()>(num[i]-'0'))
            {
                s.pop();
                k--;
            }
            s.push(num[i]-'0');
        }
        
        //Now, if k>0, we need to remove k more elements. Here K is not 0
        //because the rest of the elements in string is in increasing order.
        //So the biggest elemets will be at the top of the stack, pop stack k times
        while(k)
        {
            s.pop();
            k--;
        }
        
        //put the values from stack to string
        string result="";
        while(!s.empty())
        {
            result+=to_string(s.top());
            s.pop();
        }
        //reverse the string
        reverse(result.begin(),result.end());
        
        //check for 0's at the begining
        int index=0;
        while(result[index]=='0')
            index++;
        
        result=result.substr(index,result.length()-index);
        
        if(result.length()==0)
            return "0";
        
        return result;
        
    }
};
