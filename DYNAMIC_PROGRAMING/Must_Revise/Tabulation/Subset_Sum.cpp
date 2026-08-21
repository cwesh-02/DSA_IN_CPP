class Solution {
  public:
  
    // bool solve(vector<int>& arr, int sum , int idx , vector<vector<int>> &dp)
    // {
    //     if(sum==0) return 1;
    //     if(idx <=0) return 0;
        
    //     if(dp[idx][sum]!=-1) return dp[idx][sum];
        
    //     if(arr[idx-1]>sum) return dp[idx][sum] = solve(arr , sum , idx-1 , dp);
        
    //     else
    //     return dp[idx][sum] = solve(arr , sum-arr[idx-1] , idx-1 , dp) || solve(arr , sum , idx-1 , dp);
    // }
    
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        int idx = arr.size();
        vector<vector<int>> dp(idx+1 , vector<int>(sum+1 , 0));
        

        for(int i =0;i<=idx;i++)
        {
            dp[i][0] = 1;
        }
        for(int i =1;i<=sum;i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 1 ; i<=idx ; i++)
        for(int j = 1 ; j<=sum ;j++)
        {
            if(arr[i-1]>j)
            dp[i][j] = dp[i-1][j];
            
            else
            dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
        }
        
        return dp[idx][sum];

    }
    
};