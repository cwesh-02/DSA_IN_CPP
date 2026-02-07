/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution {
  public:
  
  int prev = INT_MIN;
  bool hasprev = 0;
  
  void solve(Node* root , int &ans)
  {
      if(!root) return;
      
      solve(root->left , ans);
      
      if(hasprev)
      {
          ans = min(ans , abs(root->data - prev));
      }
      
      prev = root->data;
      hasprev = 1;
      solve(root->right , ans);
  }
  
    int absolute_diff(Node *root) 
    {
        int ans = INT_MAX;
        solve(root , ans);
        return ans;
    }
};
