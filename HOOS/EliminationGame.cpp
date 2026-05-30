class Solution {
public:
    int lastRemaining(int n) 
    {
        int remaining=n;
        int head = 1;
        bool ltor=1;
        long long step=1;

        while(remaining>1)
        {
            if(ltor || remaining%2==1)
            {
                head+=step;
            }

            step=step*2;
            ltor=!ltor;
            remaining=remaining/2;

        }

        return head;
    }
};