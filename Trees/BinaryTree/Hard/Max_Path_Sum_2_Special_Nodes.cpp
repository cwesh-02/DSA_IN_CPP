/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  int solve(Node* root , int &sum)
  {
      if(!root)
      {
          return 0;
      }
      
      int left = solve(root->left , sum);
      int right = solve(root->right , sum);
      
      if(!root->right && !root->left)
      {
          return root->data;
      }
      
      if(root->right && root->left)
      {
         sum = max(sum , left + right + root->data);
         return max(left , right)+root->data;
      }
      
      else
      {
         // return root->data + max(left , right);  THIS IS THE MAIN DIFFERENCE IN THESSE TWO LINES
          
          //    -38
        //         \         
      //           -77

          return root->data + (root->left ? left : right);

      }
      
  }
  
    int maxPathSum(Node* root) 
    {
        
        int sum =INT_MIN;
        int value = solve(root , sum);
        
        if (sum == INT_MIN)
        return value;   
        else
        return sum;     

    }
};