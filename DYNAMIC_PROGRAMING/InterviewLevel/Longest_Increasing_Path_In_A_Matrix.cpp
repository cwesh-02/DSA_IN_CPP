class Solution {
  public:
  
    int row[4]={1 , 0 , -1 , 0};
    int col[4]={0 , -1 , 0 , 1};
    
    bool check(int i , int j , int n , int m)
    {
        return i<n && j<m && i>-1 && j >-1;
    }
    
    void DFS(int i , int j , vector<vector<int>> &matrix , vector<vector<int>> &path , int &n , int &m)
    {
        if(path[i][j]!=0) return;
        
        path[i][j]=1;
        
        for(int k =0;k<4;k++)
        {
            if(check(i+row[k] , j+col[k] , n , m) && matrix[i+row[k]][j+col[k]] > matrix[i][j])
            {
                if(path[i+row[k]][j+col[k]] == 0)
                {
                    DFS(i+row[k] , j+col[k] , matrix , path , n , m);
                    path[i][j] = max( path[i][j] , 1+ path[i+row[k]][j+col[k]] );                 

                }
                
                else
                path[i][j] = max( path[i][j] , 1+ path[i+row[k]][j+col[k]] );                 

            }
        }
    }
    
    int longIncPath(vector<vector<int>> &matrix, int n, int m) 
    {
        vector<vector<int>> path(n , vector<int>(m , 0));
        int total = 0;
        
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(path[i][j]==0)
                {
                    DFS(i , j , matrix , path , n , m);
                }
            }
        }
        
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                total = max(total , path[i][j]);
            }
        }
        
        return total;
    }
};





