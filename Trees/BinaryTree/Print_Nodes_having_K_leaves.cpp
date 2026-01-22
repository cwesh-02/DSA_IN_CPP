/*The Node is defined as follows:
struct Node
{
    int data ;
    struct Node * left, * right ;
};


class Solution {
  public:
    /*You are required to complete below method */

int solve(Node* root , int k , vector<int> &ans)
{
        if (!root)
            return 0;

        // If leaf node
        if (!root->left && !root->right)
            return 1;
            
       int left = solve(root->left , k , ans);
       int right =  solve(root->right , k ,ans);
        
        int total = left + right;
        
        if(total==k)
        {
            ans.push_back(root->data);
        }
        
        return total;
}

    vector<int> btWithKleaves(Node *ptr, int k) 
    {
        vector<int> ans;
        solve(ptr , k , ans);
        
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        
        return ans;
    }
};