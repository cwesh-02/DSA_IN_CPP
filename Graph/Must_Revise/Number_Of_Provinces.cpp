// User function Template for C++

class Solution {
  public:
 
  void DFS(vector<vector<int>> &adj , vector<bool> &visited , int node)
  {
      if(visited[node]==1)
      return;
          
      visited[node]=1;
          
      for(int i =0;i<adj[node].size();i++)
      {
          if(adj[node][i]==1 && visited[i]==0)
          DFS(adj , visited , i);
      }
  }
  
    int numProvinces(vector<vector<int>> adj, int V) 
    {
       vector<bool> visited(V,0);
       int count=0;
       for(int i =0;i<V;i++)
       {
           if(visited[i]==0)
           {
               count++;
               DFS(adj  , visited , i);
           }
       }
       return count;
    }
};