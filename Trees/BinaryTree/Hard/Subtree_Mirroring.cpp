#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root , int target , bool a = false)
{
    if(!root) return;
    if(root->val == target)
    {
        Node* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }

    else
    {
        solve(root->left , target);
        solve(root->right , target);
    }
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->right->left = new Node(10);
    root->right->right = new Node(11);

    int target = 6;
    solve(root , target);

    return 0;
}

//PENDING