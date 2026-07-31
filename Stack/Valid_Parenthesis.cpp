class Solution {
public:
    bool isValid(string a) 
    {
        stack<char> s;
        int n = a.length();

            for(int i =0;i<n;i++)
            {
                if((a[i]==')' || a[i]==']' || a[i]=='}') && s.empty()) return false;

                if(a[i]=='(' || a[i]=='[' || a[i]=='{')
                s.push(a[i]);

                else if(s.top()=='(' && a[i]!=')' || s.top()=='[' && a[i]!=']' || s.top()=='{' && a[i]!='}')
                return false;

                else
                s.pop();
            }

            if(!s.empty()) return false;

            return true;

    };
};