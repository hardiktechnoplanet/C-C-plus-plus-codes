//O(n)
//https://www.youtube.com/watch?v=AIhyd8lMpIo
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> st;
        int result=0;
        //test case
        if(s.length()==0)
        {
            return result;
        }
        st.push(-1);
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(!st.empty())
                {
                    int temp=st.top();
                    result = max(result, i - temp);
                }
                else
                    st.push(i);
            }
        }
        return result;
        
    }
};
