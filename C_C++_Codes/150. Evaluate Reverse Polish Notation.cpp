class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        //test case
        if(tokens.empty())
            return 0;
        
        stack <int> s;
        for(auto t: tokens)
        {
            if(t=="+"||t=="*"||t=="-"||t=="/")
            {
                int x=s.top(); 
                s.pop();
                int y=s.top();
                s.pop();
                switch(t.front())
                {
                    case '+':
                        y=y+x;
                        break;
                    case '-':
                        y=y-x;
                        break;
                    case '*':
                        y=y*x;
                        break;
                    case '/':
                        y=y/x;
                        break;
                }
                s.push(y);
            }
            else
                s.push(stoi(t));
        }
        return s.top();
    }
        
};
