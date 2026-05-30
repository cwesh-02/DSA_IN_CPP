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

    bool solve(TreeNode* root , TreeNode* root1)
    {
        if(!root && !root1) return true;
        if(!root || !root1) return false;
        if (root->val != root1->val) return false;

        bool left = solve(root->left , root1->right);
        bool right = solve(root->right , root1->left);

        return left && right;
    }

    bool isSymmetric(TreeNode* root) 
    {
        TreeNode* root1 = root;
        return solve(root , root1);
    }
};