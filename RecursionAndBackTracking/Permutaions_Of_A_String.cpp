class Solution {
  public:
  
  void solve(string &s , vector<string> &ans , string &temp , vector<int> &visited)
  {
        if(temp.length()==s.length())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i =0;i<s.length();i++)
        {
            if(i > 0 && s[i] == s[i-1] && visited[i-1] == 0) continue;
            
            if(visited[i]==0)
            {
                temp+=s[i];
                visited[i]=1;
                solve(s , ans , temp , visited);
                temp.pop_back();
                visited[i]=0;
            }
            
            
        }
  }
  
    vector<string> findPermutation(string &s) 
    {
        vector<string> ans;
        string temp="";
        sort(s.begin(), s.end());
        vector<int> visited(s.length() , 0);
        solve(s , ans , temp , visited);
        return ans;
    }
};
