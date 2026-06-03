class Solution {
  public:
  
  bool check(int i , int j , int row , int col)
  {
      return i<row && j<col && i>-1 && j>-1;
  }
  
  void BFS(vector<vector<int>> &box , int i , int j)
  {
        int n = box.size();
        int m = box[0].size();
        
        int row[8]={0 , -1 , 0 , 1 , -1 , 1 , -1 , 1};
        int col[8]={-1 , 0 , 1 , 0 , -1 , 1 , 1 , -1};
        
        queue<pair<int,int>> q;
        
        q.push({i,j});
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            
            for(int k =0;k<8;k++)
            {
                if(check(i+row[k] , j+col[k] , n , m)  &&  box[i+row[k]][j+col[k]] == 1)
                {
                    q.push({i+row[k] , j+col[k]});
                    box[i+row[k]][j+col[k]]=0;
                }
            }
            
            q.pop();
        }
  }
  
    int countIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> box(n, vector<int>(m, 0));
        
        for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]=='L')
            {
                box[i][j]=1;
            }
            
            else
            {
                box[i][j]=0;
            }
        }
        
        for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
        {
            if(box[i][j]==1)
            {
                count++;
                BFS(box , i , j);
            }
        }
      
      return count;  
    }
};