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
    TreeNode* construct(int preS , int preE , int postS , vector<int>& preorder , vector<int>& postorder){
        if(preS > preE)return nullptr ;

        if(preS == preE)return new TreeNode(preorder[preS]) ;

        int leftroot = preorder[preS + 1] ;

        int leftnodes = 1 ;
        while(postorder[postS + leftnodes - 1] != leftroot){
            leftnodes++ ;
        }

        TreeNode* root = new TreeNode(preorder[preS]) ;

        root->left = construct(preS + 1 , preS + leftnodes , postS , preorder , postorder) ;

        root->right = construct(preS + leftnodes + 1 , preE , postS +  leftnodes , preorder , postorder) ;

        return root ;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int nodes = preorder.size() ;
        return construct(0 , nodes - 1 , 0 , preorder , postorder) ;
    }
};