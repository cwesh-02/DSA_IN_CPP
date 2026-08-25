class Solution {
  public:
  
    int solve(int &n , vector<int> &arr , int i , int j , vector<vector<int>> &dp)
    {
        
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==j) return arr[i];
        
        int c1 = arr[i] + min ( solve(n , arr , i+2 , j , dp) , solve(n , arr , i+1 , j-1 , dp));
        int c2 = arr[j] + min ( solve(n , arr , i+1 , j-1 , dp) , solve(n , arr , i , j-2 , dp));
        
        return dp[i][j] = max(c1 , c2);
    }
  
    int maximumAmount(vector<int> &arr) 
    {
        int n = arr.size();
        int i = 0;
        int j = n-1;
        
        vector<vector<int>> dp(n , vector<int>(n,-1));
        return solve(n , arr , i , j , dp);
        
    }
};