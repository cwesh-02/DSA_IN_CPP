#include<iostream>
using namespace std;

class Node
{
public:
int data , height;
Node* left , *right;

    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int GetHeight(Node* root)
{
    if(!root) return NULL;
    return root->height;
}

void UpdateHeight(Node* root)
{
    int LeftHeight=GetHeight(root->left);
    int RightHeight=GetHeight(root->right);
    root->height=1+max(LeftHeight , RightHeight);
}

Node* RotateRight(Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

Node* RotateLeft(Node* root)
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

Node* Balance(Node* root)
{
    if(!root)
    {
        return NULL;
    }


}

Node* InsertBST(Node* root , int value)
{
    if(!root)
    {
        return new Node(value);
    }

    if(value<root->data)
    {
        root->left = InsertBST(root->left , value);
    }
    else
    root->right = InsertBST(root->right , value);

    return Balance(root);
}

int main()
{
    Node* root = NULL;
    int value;
    while(1)
    {
        if(value!=-1)
        {
            root=InsertBST(root,value);
        }
        else
        break;
    }
    return 0;
}