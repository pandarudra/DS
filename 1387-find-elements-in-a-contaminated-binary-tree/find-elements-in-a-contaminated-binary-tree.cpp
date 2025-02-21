#define uset unordered_set
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
class FindElements {
private:
    TreeNode* root ;
    uset<int> s ;
    void Recover(TreeNode*& root){
        if(root == nullptr)return ;

        if(root -> left != nullptr){
            root->left->val = 2 * (root->val) + 1 ;
            s.insert(root->left->val) ;
            Recover(root->left) ;
        }
        if(root -> right != nullptr){
            root->right->val = 2 * (root->val) + 2 ;
            s.insert(root->right->val) ;
            Recover(root->right) ;
        }
    }
    
public:
    FindElements(TreeNode* root) {
        TreeNode* node = root ;
        node->val = 0 ;
        s.insert(0) ;
        Recover(node) ;
    }
    
    bool find(int target) {
        return s.count(target) ;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */