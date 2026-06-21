class Solution {
public:
    bool isValid(int i, int j, int row, int col) {
        return i < row && j < col && i > -1 && j > -1;
    }

    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        queue<pair<int,int>> q;

        bool flag = 0;
        for(int i =0;i<grid.size();i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                q.push({i , j});
                visited[i][j]=1;
                flag=true;
                break;
                }
            }
            if(flag==true) break;
        

        if(flag==true) break;
        }

        int row[4] = {-1 , 1 , 0 , 0};
        int col[4] = {0 , 0 , 1 , -1};
        int ans = 0;

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            

            for(int k =0;k<4;k++)
            {
                if(!isValid(i+row[k] , j+col[k] , n , m) || grid[i+row[k]][j+col[k]]==0)
                {
                    ans++;
                }

                else
                {
                    if(!visited[i+row[k]][j+col[k]])
                    q.push({i+row[k] , j+col[k]});
                    visited[i+row[k]][j+col[k]]=1;
                }
            }            
        }

        return ans;

    }
};