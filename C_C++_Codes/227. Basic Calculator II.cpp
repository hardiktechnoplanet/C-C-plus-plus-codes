class Solution {
public:
    int calculate(string s) 
    {
        //test case: empty string
        if(s.length()==0)
        {
            return 0;
        }
        
        //stack to stores the values
        stack<int> values;
        //stack to store the operators
        stack<char> ops;
        
        for(size_t i=0;i<s.length();++i)
        {
            //white space
            if(s[i]==' ')
                continue;
            
            //integer
            else if(isdigit(s[i]))
            {
                int val=0;
                while(i<s.length() && isdigit(s[i]))
                {
                    val=val*10+(s[i]-'0');
                    i++;
                }
                values.push(val);
                i--;
            }
            
             //current element is an operator
            else
            {
                // While top of 'ops' has same or greater  
                // precedence to current token, which 
                // is an operator. Apply operator on top  
                // of 'ops' to top two elements in values stack.
                while(!ops.empty() && precedence(ops.top()) 
                                >= precedence(s[i]))
                {
                    //get the top two values from the value stack
                    int val2=values.top();
                    values.pop();
                    int val1=values.top();
                    values.pop();
                    
                    //get the operator
                    char op=ops.top();
                    ops.pop();
                    
                    //solve the equation and push the value in the value stack
                    values.push(applyOperator(val1,val2,op)); 
                }
                //push the current operator to ops
                ops.push(s[i]);
            }
        }
        // Entire expression has been parsed at this 
        // point, apply remaining ops to remaining values.
        while(!ops.empty())
        {
            //get the top two values from the value stack
            int val2=values.top();
            values.pop();
            int val1=values.top();
            values.pop();

            //get the operator
            char op=ops.top();
            ops.pop();

            //solve the equation and push the value in the value stack
            values.push(applyOperator(val1,val2,op));   
        }
        return values.top();     
        
    }
    
    // Function to perform arithmetic operations. 
    int applyOperator(int a, int b, char op){ 
        switch(op){ 
            case '+': return a + b; 
            case '-': return a - b; 
            case '*': return a * b; 
            case '/': return a / b; 
        } 
        return 0;
    }
    // Function to find precedence of  
    // operators.
    int precedence(char op)
    {
        if(op=='+' || op=='-')
            return 1;
        if(op=='*' || op=='/')
            return 2;
        return 0;
    }
};
