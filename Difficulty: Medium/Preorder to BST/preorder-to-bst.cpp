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
  private:
  Node* build(int pre[] , int left , int right) {
      if(left > right) return nullptr ;
      
      Node* root = newNode(pre[left]) ;
      
      int mid = left + 1 ;
      
      while(mid <= right && pre[mid] <= pre[left]) mid++ ;
      
      root->left = build(pre , left + 1 , mid - 1) ;
      root->right = build(pre , mid , right) ;
      
      return root ;
  }
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        return build(pre , 0 , size - 1) ;
    }
};