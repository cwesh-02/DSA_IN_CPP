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

    int ans =0;

    void solve(TreeNode* root , int target , long long sum)
    {
        if(!root) return;

        sum+=root->val;

        if(sum==target)
        {
            ans++;
        }

        solve(root->left , target , sum);
        solve(root->right , target , sum);
        
    }

    int pathSum(TreeNode* root, int target) 
    {
        if(!root) return 0;

        int sum =0;

        solve(root, target , sum);
        pathSum(root->left , target);
        pathSum(root->right , target);
        
        return ans;
    }
};