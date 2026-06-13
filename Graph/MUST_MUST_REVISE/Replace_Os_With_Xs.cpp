class Solution {
  public:
  
    bool check(int i , int j , int n , int m)
    {
        return i<n && j<m && i>-1 && j>-1;
    }
  
    void fill(vector<vector<char>>& grid) 
    {
        int row[4] = {1 , -1 , 0 , 0};
        int col[4] = {0 , 0 , 1 , -1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i =0;i<n;i++)
        {
            if(grid[i][0]=='O')
            {
            q.push({i,0});
            grid[i][0] = '#';
            }
            
            if(grid[i][m-1]=='O')
            {
            q.push({i , m-1});
            grid[i][m-1] = '#';
            }
        }
        
        for(int j=1;j<m-1;j++)
        {
            if(grid[0][j]=='O')
            {
            q.push({0,j});
            grid[0][j] = '#';
            }
        }
        
        for(int j=m-2;j>=1;j--)
        {
            if(grid[n-1][j]=='O')
            {
                q.push({n-1,j});
                grid[n-1][j] = '#';
            }
        }
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            
            for(int k =0;k<4;k++)
            {
                if(check(i+row[k] , j+col[k] , n , m) && grid[i+row[k]][j+col[k]]=='O')
                {
                    q.push({i+row[k] , j+col[k]});
                    grid[i+row[k]][j+col[k]]='#';
                }
            }
            
            q.pop();
        }
        
        for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]=='O')
            {
                grid[i][j]='X';
            }
            
            else if(grid[i][j]=='#')
            {
                grid[i][j]='O';
            }
        }
        

    }
};