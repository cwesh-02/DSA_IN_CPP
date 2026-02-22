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
        if(root==p || root== q) return root;
        if(root->left == p && root->right == q) return root;

        TreeNode* left = solve(root->left , p , q);
        TreeNode* right = solve(root->right , p , q);
        
        if(left && right) return root;
        if(!left) return right;
        if(!right) return left;
        
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p->left==q || p->right==q)
        return p;
        if(q->left ==p|| q->right==p)
        return q;

        return solve(root , p , q);
    }
};