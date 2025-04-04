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
class Solution {
private:
    int maxDepth(TreeNode* root){
        if(!root)return 0 ;
        return 1 + max(maxDepth(root->left) , maxDepth(root->right)) ;
    }
    TreeNode* findLCA(TreeNode* root , int d , int md){
        if(!root) return nullptr ;
        if(d == md){
            return root ;
        }
        TreeNode* left = findLCA(root->left , d + 1 , md) ;
        TreeNode* right = findLCA(root->right , d + 1 , md) ;
        if(left && right) return root ;
        return left ? left : right ;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int md = maxDepth(root) ;
        return findLCA(root , 1 , md) ;
    }
};