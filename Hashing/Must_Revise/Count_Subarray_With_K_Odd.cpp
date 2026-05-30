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
vector<TreeNode*> ans;
    string solve(TreeNode* root , unordered_map<string,int> &m)
    {
       // SOLVE AFTER HASHING
       //Back after learning hashing!
        if(!root) return "N";

        string temp = to_string(root->val) + "," + solve(root->left , m) + "," + solve(root->right , m);
        if(m[temp]==1)
        {
            ans.push_back(root);
        }

        m[temp]++;
        return temp;

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string,int> m;

        solve(root , m);
        return ans;
    }
};