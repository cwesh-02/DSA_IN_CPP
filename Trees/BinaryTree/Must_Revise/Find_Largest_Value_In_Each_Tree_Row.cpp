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
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> tempans;
        vector<int> ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            int current_max = INT_MIN;
            
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();

                current_max = max(current_max, temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            
            }

            ans.push_back(current_max); 

            }

        return ans;
    }
};