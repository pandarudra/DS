/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  private:
    int sum(Node* node) {
        if(node == nullptr) return 0 ;
        int Lsum = sum(node->left) ;
        int Rsum = sum(node->right) ;
        
        return node->data + Lsum + Rsum ;
    }
  public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        if(node == nullptr) return ;
        int t = node->data ;
        node->data = sum(node) - t ;
        toSumTree(node->left) ;
        toSumTree(node->right) ;
    }
};