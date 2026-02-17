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
    int prev=-1;
    void inorder(TreeNode* root , int &minsum)
    {
        if(!root) return;
        
        inorder(root->left , minsum);
        if(prev!=-1)
        {
            minsum=min(minsum , abs(prev-root->val));
        }
        prev = root->val;

        inorder(root->right , minsum);
    }

    int getMinimumDifference(TreeNode* root) 
    {
        int minsum = INT_MAX;
        inorder(root , minsum);
        return minsum;
    }
};