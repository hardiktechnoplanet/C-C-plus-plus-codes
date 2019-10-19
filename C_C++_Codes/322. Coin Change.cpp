//bottom up dynamic programming
//https://www.youtube.com/watch?v=1R0_7HqNaW0&t=362s
//Time complexity=O(nm) when n is amount and m is coins
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        //test case
        if(coins.size()==0)
            return 0;
        
        //declare a vector to store the intermediate results
        //T[n] represents the min number of coins to make n cents
        //fill up the T vector with some thing invalid(> the amount)
        vector<int> T(amount+1,amount+1);
        //it will take 0 coins to make 0 cents
        T[0]=0;
        
        //i represents how many cents we are trying to make up
        for(size_t i=1;i<=amount;++i)
        {
            for(size_t j=0;j<coins.size();++j)
            {
                //if the i cent is greater than the coin value
                if(i>=coins[j])
                {
                    //T[i] will be min of T[i] if we dont take the 
                    // coin at j or if we take the coin j than the equation
                    //becomes 1+ number of coins required to make up amount left
                    T[i]=min(T[i],1+T[i-coins[j]]);
                }
            }
        }
        
        return T[amount]>amount ? -1 : T[amount];
    }
};
