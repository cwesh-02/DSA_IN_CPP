class Solution {
public:

void solve(int n , int OB , int CB , vector<int> &ans , string temp)
{
    if(OB<CB) return;
    if(OB>n) return;
    if(OB+CB == 2*n) 
    {
        ans.push_back(temp);
        return;
    }
    solve(n , OB+1 , CB , ans , temp+"(");
    temp.pop_back();
    solve(n , OB , CB+1 , ans , temp+")");
}

    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string temp ="";
        solve(n , 0 , 0 , ans , temp);
        return ans;
    }
};