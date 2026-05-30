class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) 
    {
        vector<string> ans;
        string hour;
        string min;
        for(int i =0;i<12;i++)
        {
            for(int j =0;j<60;j++)
            {
                if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn)
                {
                     hour = to_string(__builtin_popcount(i));
                     if(j<10)
                     {
                        min = "0" + to_string(__builtin_popcount(j));
                     }
                     else
                     min = to_string(__builtin_popcount(j));

                    ans.push_back(hour+":"+min);

                } 
            }
        }
    
    return ans;
    }
};