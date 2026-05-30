class Solution {
public:
    string convert(long long x,long long y){
        string temp = "";
        temp += to_string(x);
        temp += "_";
        temp += to_string(y);
        return temp;
    }
    long long euclidean(long long x, long long y){
        return (x * x) + (y * y);
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        unordered_map<string , int> mp;
        for(auto i: obstacles)
        {
            string temp = "";
            temp += to_string(i[0]);
            temp += "_";
            temp += to_string(i[1]);
            mp[temp]++;
        }

        long long x = 0;
        long long y = 0;
        // for(auto i : mp){
        //     cout<<i.first<<endl;
        // }
        
        long long cl = commands.size();
        
        long long dir = 0,ans=0;

        for(long long i =0;i<cl;i++)
        {
            if(commands[i]==-2 || commands[i]==-1)
            {
                if(commands[i]==-1)
                {
                    dir++;
                    dir = (dir+4)%4;
                }

                else
                {
                    dir--;
                    dir = (dir+4)%4;
                }
            }

            else
            {
                for(long long j =0;j<commands[i];j++)
                {

                    

                    if(dir == 1)  //x axis change
                    {
                        string temp = convert(x+1,y);
                        if(mp[temp]==1){
                            break;
                        }
                    x++;
                    ans = max(ans,euclidean(x,y));
                    }     

                    if(dir==3)
                    {
                        string temp = convert(x-1,y);
                        if(mp[temp]==1){
                            break;
                        }
                    x--;
                    ans = max(ans,euclidean(x,y));
                    }

                    if(dir == 0)
                    {
                        string temp = convert(x,y+1);
                        if(mp[temp]==1){
                            break;
                        }
                    y++;
                    ans = max(ans,euclidean(x,y));

                    }

                    if(dir==2)
                    {
                        string temp = convert(x,y-1);
                        if(mp[temp]==1){
                            break;
                        }
                    y--;
                    ans = max(ans,euclidean(x,y));

                    }
                }
            }  //else

        }

        return ans;
    }
};