class Solution {
public:
    int countKthRoots(int l, int r, int k) 
    {
        int count=0;
        
        if(k == 1)
        return r - l + 1;
        
        for(long long i =1;;i++)
            {
               long long val = 1;
               int t = k;
                
               while(t--)
                   {
                       if(val>r/i)  // val*i > r
                       {
                           val=r+1;
                           break;
                       }
                       
                       val = val*i;
                   }
                
                if(val>r) break;
                if(val>=l) count++;
            }
        
        if(l==0) count++;
        return count;
    }
};



EASY METHOD

class Solution {
public:
    int countKthRoots(int l, int r, int k) 
    {
        int count=0;
        int st = pow(l,1.0/k);
        if(k==1) return r-l+1;
        for(int i = st;;i++)
        {
            if(pow(i,k)>=l && pow(i,k)<=r)
            {
                count++;
            }

            if(pow(i,k)>r)
            break;

        }
        return count;
    }
};