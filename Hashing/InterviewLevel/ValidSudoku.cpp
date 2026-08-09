class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int i =0;i<9;i++)
        {
            set<int> s;
            for(int j = 0;j<9;j++)
            {
                if(board[i][j]=='.') continue;

                else
                {
                    if(s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    else
                    s.insert(board[i][j]);
                }
            }
        }

        for(int i =0;i<9;i++)
        {
            set<int> s;
            for(int j = 0;j<9;j++)
            {
                if(board[j][i]=='.') continue;

                else
                {
                    if(s.find(board[j][i]) != s.end())
                    {
                        return false;
                    }
                    else
                    s.insert(board[j][i]);
                }
            }
        }

    for(int boxrow = 0;boxrow<9;boxrow+=3)
    {
        for(int boxcol= 0;boxcol<9;boxcol+=3)
        {
            set<int> s;
            for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                char val = board[boxrow+i][boxcol+j];
                if(val=='.') continue;

                else
                {
                    if(s.find(val) != s.end())
                    {
                        return false;
                    }
                    else
                    s.insert(val);
                }
            }

        }
    }


        return true;
    }
};