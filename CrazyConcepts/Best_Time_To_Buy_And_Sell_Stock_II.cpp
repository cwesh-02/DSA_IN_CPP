class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int stock = prices[0];
        int n = prices.size();
        for(int i =1;i<n;i++)
        {
            if(prices[i]-stock>0)
            {
                profit+=prices[i]-stock;
                stock = prices[i];
            }

            else
            stock = prices[i];
        }

        return profit;
    }
};