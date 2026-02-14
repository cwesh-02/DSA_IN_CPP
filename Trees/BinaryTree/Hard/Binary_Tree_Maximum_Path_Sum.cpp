#include<bits/stdc++.h>
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

    int solve(TreeNode* root , int &sum , int &ans)
    {
        if(!root) return 0;
        int left = solve(root->left , sum , ans);
        int right = solve(root->right , sum ,ans);

        if(left+right+root->val>ans)
        {
            ans=left+right+root->val;
        }

        if(left+root->val>ans)
        {
            ans=left+root->val;
        }

        if(right+root->val>ans)
        {
            ans=right+root->val;
        }

        if(root->val>ans)
        {
            ans=root->val;
        }

        return max((root->val) , max((root->val)+left  , (root->val)+right ));
    }

    int maxPathSum(TreeNode* root) 
    {
        int ans=INT_MIN;
        int sum=0;
        solve(root , sum , ans);
        return ans;
    }
};