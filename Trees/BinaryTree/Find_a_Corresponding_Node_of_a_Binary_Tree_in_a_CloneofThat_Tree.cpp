/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(TreeNode* root , TreeNode* cloned , TreeNode* target)
    {
        if(!root) return NULL;
        if(root==target) return cloned;

        TreeNode* left = solve(root->left , cloned->left ,  target);
        TreeNode* right =solve(root->right , cloned->right , target);
        if(left) return left;
        else return right;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
       return solve(original , cloned , target);
    }

};