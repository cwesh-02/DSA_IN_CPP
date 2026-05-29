#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void solve(TreeNode* root)
{
    if(!root) return;
    solve(root->left);
    cout<<root->data;
    solve(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);

    solve(root);

    return 0;
}