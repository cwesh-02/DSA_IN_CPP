class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int count=0;
        int n = nums.size();
        int i=0;
        int start;

        if(nums.size()<4)
        {
            return false;
        }

        start=i;

        while((i<n-1)&&(nums[i]<nums[i+1]))
        {
            cout<<1<<" "<<i<<endl;
            i++;
        }

        if(i==start)
        return false;
        
        count++;

        start = i;
        while((i<n-1)&& nums[i]>nums[i+1])
        {
            cout<<2<<" "<<i<<endl;
            i++;
        }
        if(i==start)
        return false;
        
        count++;

        start=i;

        while((i<n-1) && nums[i]<nums[i+1] )
        {
            cout<<3<<" "<<i<<endl;
            i++;
        }

        if(i==start)
        return false;

        count++;

        if(i==nums.size()-1 && count==3) 
        return true;

        else
        return false;
        

    }
};