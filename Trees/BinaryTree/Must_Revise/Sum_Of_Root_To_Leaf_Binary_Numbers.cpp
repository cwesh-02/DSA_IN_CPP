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

    int ans=0;
    int solve(TreeNode* root , int value)
    {
        if(!root) return 0;
                
        value = value*2 + root->val;

        if(!root->left && !root->right)
        return value;

        return solve(root->left , value) + solve(root->right , value);
    }

    int sumRootToLeaf(TreeNode* root) 
    {
        int value = 0;
        return solve(root , value);
        
    }
};