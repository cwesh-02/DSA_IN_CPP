/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxfreq=0;
    vector<int> ans;
    long long prevval = LLONG_MIN;
    int count = 1;

    void solve(TreeNode* root)
    {
        if(!root) return;
        
        solve(root->left);

        if(root->val==prevval)
        {
            count++;
        }

        else
        {
            prevval = root->val;
            count=1;
        }
        
        if(count>maxfreq)
            {
                maxfreq = count;
                while(ans.size()!=0)
                ans.pop_back();
 
                ans.push_back(root->val);
            }

        else if(count==maxfreq)
        {
            ans.push_back(root->val);
        }

        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) 
    {
        solve(root);
        return ans;
    }
};