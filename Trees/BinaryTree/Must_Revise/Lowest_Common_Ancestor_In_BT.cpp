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

    TreeNode* solve(TreeNode* root , TreeNode* p , TreeNode* q)
    {
            if(!root) return NULL;

            if(root==p)
            return root;

            if(root==q)
            return root;

        TreeNode* leftside = solve(root->left , p , q);
        TreeNode* rightside = solve(root->right , p , q);

        if(leftside && rightside)
        return root;

        if(!leftside && rightside)
        return rightside;

        else
        return leftside;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return solve(root , p , q);
    }
};