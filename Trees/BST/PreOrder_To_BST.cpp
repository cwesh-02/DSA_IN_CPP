// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:

    Node* solve(int pre[] , int &size , int min , int max , int &idx)
    {
        if(idx >= size)
        {
            return NULL;
        }

        if(pre[idx]>max || pre[idx]<min)
        {
            return NULL;
        }
        
        Node* temp = newNode(pre[idx]);
        idx++;
        
        temp->left = solve(pre , size , min , temp->data , idx);
        temp->right = solve(pre , size , temp->data , max , idx);
        
        return temp;
    }

    Node* Bst(int pre[], int size) 
    {
        int min = INT_MIN;
        int max = INT_MAX;
        int idx =0;
        return solve(pre , size , min , max , idx);
                
    }
};