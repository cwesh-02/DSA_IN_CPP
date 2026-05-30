int maxProfit(vector<int>& arr) {
        int minPrice = INT_MAX;
        int maxx = 0;
  
        for (int price : arr) 
        {
            minPrice = min(price, minPrice);
            maxx = max(price - minPrice, maxx);

        }

        return maxx;
    }