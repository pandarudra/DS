/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  private:
    int h(Node *root) {
        if(root == nullptr) return 0 ;
        return 1 + max(h(root->left) , h(root->right)) ;
    }
  public:
    bool isBalanced(Node* root) {
        queue<Node*> q ;
        q.push(root) ;
        
        while(!q.empty()) {
            Node* node = q.front() ;
            q.pop() ;
            
            int lh = h(node->left) ;
            int rh = h(node->right) ;
            
            if(abs(lh - rh) > 1) return false ;
            
            if(node->left != nullptr) q.push(node->left) ;
            if(node->right != nullptr) q.push(node->right) ;
        }
        
        return true ;
    }
};