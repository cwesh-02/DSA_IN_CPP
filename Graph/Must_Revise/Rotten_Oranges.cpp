class Solution {
  public:
  
    int orangesRot(vector<vector<int>>& grid) 
    {
        queue<pair<pair<int,int>,int>> q;
        int goodoranges=0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i =0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            goodoranges++;
            
            else if(grid[i][j]==2)
            q.push({{i,j} , 0});
        }
        
        
        int timer=0;
        
        while(!q.empty())
        {
            
            int i = q.front().first.first;
            int j = q.front().first.second;
            timer = q.front().second;
            
            if(i<n && j<m && i-1>-1)
            {
                if(grid[i-1][j]==1)
                {
                    grid[i][j]=0;
                    grid[i-1][j]=2;
                    goodoranges--;
                    q.push({{i-1,j} , timer+1});
                }
            }
            
            if(i<n && j<m && i+1<n)
            {
                if(grid[i+1][j]==1)
                {
                    grid[i][j]=0;
                    grid[i+1][j]=2;
                    goodoranges--;
                    q.push({{i+1,j} , timer+1});
                }
            }
            
            if(i<n && j<m && j+1<m)
            {
                if(grid[i][j+1]==1)
                {
                    grid[i][j]=0;
                    grid[i][j+1]=2;
                    goodoranges--;
                    q.push({{i,j+1} , timer+1});
                }
            }
            
            if(i<n && j<m && j-1>-1)
            {
                if(grid[i][j-1]==1)
                {
                    grid[i][j]=0;
                    grid[i][j-1]=2;
                    goodoranges--;
                    q.push({{i,j-1} , timer+1});
                }
            }
            
            q.pop();
            
        }
        
        if(goodoranges)
        return -1;
        
        return timer;
        
    }
    
};

