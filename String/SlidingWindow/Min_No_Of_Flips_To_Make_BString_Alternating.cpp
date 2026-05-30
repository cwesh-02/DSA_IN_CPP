class Solution {
public:
    int minFlips(string s) 
    {
        int n = s.size();
        string doubled = s + s;
        char miss_A = 0, miss_B = 0;

        for(int i =0;i<n;i++)
        {
            int a=0,b=0;
            if(i%2==0)
            {
                a=0;
                b=1;
            }
            else
            {
                a=1;
                b=0;
            }

            if(a!=doubled[i]) miss_A++;
            if(b!=doubled[i]) miss_B++;

        }

        int ans = min(miss_A , miss_B);

        for(int i =n ;i<2*n ; i++)
        {
            char a=0,b=0;
            if(i%2==0)
            {
                a='0';
                b='1';
            }
            else
            {
                a='1';
                b='0';
            }

            if(a!=doubled[i]) miss_A++;
            if(b!=doubled[i]) miss_B++;

            int left = i-n;
            char leftkaa;
            char leftkab;

            if(left%2==0)
            {
                leftkaa='0';
                leftkab = '1';
            }
            if(left%2==1)
            {
                leftkaa='1';
                leftkab = '0';
            }

            if(doubled[left]!=leftkaa) miss_A--;
            if(doubled[left]!=leftkab) miss_B--;

            ans = min(ans , min(miss_A , miss_B));
        }

        return ans;
    }

};