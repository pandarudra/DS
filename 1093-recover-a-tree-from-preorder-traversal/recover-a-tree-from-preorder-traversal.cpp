#define umap unordered_map
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
public:
    TreeNode* recoverFromPreorder(string traversal) {
        umap <int , TreeNode*> mp ;
        TreeNode* root = new TreeNode(-1) ;
        TreeNode* node = root ;
        mp[-1] = node ;
        int n = traversal.length() ;
        for(int i = 0 ; i < n ; ){
            int d = 0 ;
            while(i < n && traversal[i] == '-'){
                d++ ;
                i++ ;
            }
            string num = "" ;
            while(i < n && isdigit(traversal[i])){
                num += traversal[i] ;
                i++ ;
            }
            TreeNode* add = new TreeNode(stoi(num)) ;
            TreeNode* parent = mp[d - 1] ;

            if(parent->left){
                parent->right = add ;
            }else{
                parent->left = add ;
            }
            mp[d] = add ;
        }
        return root->left ;
    }
};