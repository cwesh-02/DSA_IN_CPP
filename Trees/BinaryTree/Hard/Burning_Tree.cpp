/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  void Find(Node* root , int target , Node* &temp)
  {
      if(!root) return;
      
      if(root->data == target)
      {
          temp = root;
          return;
      }
      
      Find(root->left , target , temp);
      Find(root->right , target , temp);
  };
  
  int Height(Node* root)
  {
      if(!root) return 0;
      
      return 1+ max(Height(root->left),Height(root->right));
      
  };
  
  int solve(Node* root , int &target , int &timer)
  {
        if(!root)
        {
            return 0;
        }
        //TargetNode
        if(root->data==target)
        {
            return -1;
        }
        
        int left = solve(root->left , target , timer);
        int right = solve(root->right , target , timer);
        
        if(left<0)
        {
            timer = max(timer , abs(left) + right);
            return left-1;
        }
        
        if(right<0)
        {
            timer = max(timer , left + abs(right));
            return right-1;
        }
        
        return 1+max(left,right);
        
  }
  
    int minTime(Node* root, int target) 
    {
        int timer = 0;
        solve(root , target , timer);
        
        Node* temp;
        Find(root , target ,temp);
        int h = Height(temp)-1;
        
        return max(timer , h);
    }
};