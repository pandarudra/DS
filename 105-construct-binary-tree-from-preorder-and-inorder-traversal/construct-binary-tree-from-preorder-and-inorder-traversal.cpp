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
#define umap unordered_map
class Solution {
private:
    umap<int , int> InMap ;
    // node - index
    int PreI = 0 ;
    TreeNode* build(vector<int>& pre , vector<int>& in , int left , int right) {
        if(left > right) return nullptr ;
        
        int rootData = pre[PreI++] ;
        TreeNode* root = new TreeNode(rootData) ;

        int mid = InMap[rootData] ;

        root->left = build(pre , in , left , mid - 1) ;
        root->right = build(pre , in , mid + 1 , right) ;

        return root ;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int N = inorder.size() ;
        for(int i = 0 ; i < N ; i++) {
            InMap[inorder[i]] = i ;
        }
        return build(preorder , inorder , 0 , N - 1) ;        
    }
};