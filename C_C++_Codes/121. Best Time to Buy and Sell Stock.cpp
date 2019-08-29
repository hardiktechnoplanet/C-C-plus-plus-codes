class Solution {
public:
    int maxProfit(vector<int>& prices) 
	{
		//variable to store our max profit
		int maxProfit=0;
		//smallest value that we have seen
		int min=INT_MAX;
		for(size_t i=0;i<prices.size();++i)
		{
			//if the current value is smaller than the min value
			if(prices[i]<min)
			{
				min=prices[i];
			}
			else
			{
				//calculate the profit we would have sell the stock today
				maxProfit=max(maxProfit,prices[i]-min);
			}
		}
		return maxProfit;
        
    }
};
