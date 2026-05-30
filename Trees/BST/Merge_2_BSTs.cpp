/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  void solve(Node* root , vector<int> &v)
  {
      if(!root) return;
      
      solve(root->left , v);
      v.push_back(root->data);
      solve(root->right , v);
  }
  
    vector<int> merge(Node *root1, Node *root2) 
    {
        
        vector<int> v1;
        vector<int> v2;
        vector<int> ans;
        
        solve(root1 , v1);
        solve(root2 , v2);
        
        int i =0;
        int j =0;

        while(i<v1.size() && j<v2.size())
        {
            if(v1[i]<=v2[j])
            {
                ans.push_back(v1[i]);
                i++;
            }
            
            else
            {
                ans.push_back(v2[j]);
                j++;
            }
        }
        
        while(i<v1.size())
        {
            ans.push_back(v1[i]);
            i++;
        }
        
        while(j<v2.size())
        {
            ans.push_back(v2[j]);
            j++;
        }
        
        return ans;
    }
};