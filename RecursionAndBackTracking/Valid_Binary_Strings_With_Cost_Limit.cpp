class Solution {
public:
    vector<string> alls;
    
    void solve(string temp , char prev , int n , int k)
    {
        if(n==0)
        {
            alls.push_back(temp);
            return;
        }

        solve(temp+'0' , '0' , n-1 , k);

        if(prev!='1')
        solve(temp+'1' , '1' , n-1 , k);

    }
    
    vector<string> generateValidStrings(int n, int k) 
    {
        solve("" , '0' , n , k);
        vector<string> final;
        for(int i =0;i<alls.size();i++)
            {
                int cost = 0;
                
                for(int j =0;j<alls[i].size();j++)
                    {
                        if(alls[i][j]=='1')
                            cost+=j;
                    }

                if(cost<=k)
                    final.push_back(alls[i]);
            }
        
        return final;
    }
};