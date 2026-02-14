class Solution {
  public:
  void permute(vector<int>arr,vector<vector<int>>&ans,vector<bool>visited,vector<int>temp)
  {
      if(temp.size()==arr.size())
      {
          ans.push_back(temp);
          return;
      }
      
      for(int i =0;i<arr.size();i++)
      {
          if(visited[i]==0)
          {
              temp.push_back(arr[i]);
              visited[i]=1;
              permute(arr , ans , visited , temp);
              temp.pop_back();
              visited[i]=0;
          }
      }
  }
  
    vector<vector<int>> permuteDist(vector<int>& arr) {
        
        vector<vector<int>>ans;
        vector<bool>visited(arr.size(),0);
        vector<int>temp;
        
        permute(arr,ans,visited,temp);
        return ans;
    }
};