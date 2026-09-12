class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int slen = s.length();
        int plen = p.length();

        vector<int> ans;

        unordered_map<char , int> mp;
        unordered_map<char , int> test;

        int sp = plen-1;

        for(int i =0;i<plen;i++)
        {
            test[p[i]]++;
        }

int temp = 0;

for(int i =0;i<plen;i++)
{
    mp[s[i]]++;
}

int fp = 0;

        while(sp<slen)
        {
            if(mp==test) 
            ans.push_back(fp);

            mp[s[fp]]--;

            if (mp[s[fp]] == 0) {
                mp.erase(s[fp]); // Crucial: Erase zero-count keys for map equality to work
            }

            sp++;
            if (sp < slen) {
                mp[s[sp]]++;
            }
            fp++;
        }

        return ans;

    }
};