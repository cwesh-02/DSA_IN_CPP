class Solution {
public:

    int isValid(int row , int col , int i , int j)
    {
        return j>-1 && i>-1 && i<row && j<col;
    }

    void BFS(vector<vector<int>>& grid , int i , int j , int &count)
    {
        int row[4] = {1 , 0 , -1 , 0};
        int col[4] = {0 , 1 , 0 , -1};
        int c =0;
        queue<pair<int,pair<int,int>>> q;
        //i , j , count
        q.push({i , {j , count}});
        grid[i][j]=0;

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second.first;
            q.pop();
            c++;

            for(int k =0;k<4;k++)
            {
                if(isValid(grid.size() , grid[0].size() , i+row[k] , j+col[k] ) && grid[i+row[k]][j+col[k]]==1)
                {
                    grid[i+row[k]][j+col[k]]=0;
                    q.push({i+row[k],{j+col[k] , c}});
                }
            }
        }

        count = max(c , count);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int count = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j]==1)
                {
                    BFS(grid , i , j , count);
                }
            }
        }

        return count;

    }
};