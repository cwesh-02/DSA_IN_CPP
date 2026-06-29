class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        vector<int> rank(26,0);
        int n = words.size();
        for(int i =0;i<order.length();i++)
        {
            rank[order[i]-'a'] = i;
        }

        for(int i =0;i<n-1;i++)
        {
            bool flag = 0;
            int x = min(words[i].length() , words[i+1].length());
            for(int j =0;j<x;j++)
            {
                if(rank[words[i][j]-'a'] > rank[words[i+1][j]-'a'])
                return false;

                else if(rank[words[i][j]-'a'] < rank[words[i+1][j]-'a'])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag!=1 && words[i].length()>words[i+1].length())
            return false;
        }

        return true;
        // [8 , 12 , 0 , 1 , 2 , 3]

    }
};