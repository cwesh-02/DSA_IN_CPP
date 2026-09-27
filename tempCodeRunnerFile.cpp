#include <bits/stdc++.h>
using namespace std;


    bool solve(vector<int> temp , unordered_map<int , int> mp)
    {
        int mapsize = mp.size();

        int count = 0;
        for(int i = 0;i<temp.size();i++)
        {
            if(mp[temp[i]]==0) return 0;
            
            else{
                mp[temp[i]]--;
                count++;
            }
        }

        if(count == mapsize)
        return 1;

        else
        return 0;
    }

    int main()
    {

        vector<int> nums = {1,3,1,2,2};

        unordered_map<int,int> mp;
        int n = nums.size();

        vector<int> temp;

        for(int i =0;i<n;i++)
        {
            if(mp[nums[i]]==0) mp[nums[i]]++;
        }

        int fp = 0;
        int sp = 0;
        int count = 0;

        while(sp<n)
        {
            temp.push_back(nums[sp]);
    
            if(solve(temp , mp))
            {
                count++;
                count+=n-temp.size();
                fp++;
                temp.erase(temp.begin());
                sp++;
            } 

            else
            sp++;
        }

        cout<< count;

    }