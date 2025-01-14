#define uset unordered_set
#define umap unordered_map
class Solution {
public:
    
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        umap<int , int> mp ;
        int n = A.size() ;
        vector<int> prefixCnt(n , 0) ;
        int cnt = 0 ;
        for(int i = 0 ; i < n  ; i++){
            mp[A[i]]++ ;
            mp[B[i]]++;
            
            if(A[i] != B[i]){
                if(mp[A[i]] > 1)cnt++ ;
                if(mp[B[i]] > 1)cnt++ ;
            }else{
                cnt++ ;
            }
            

            prefixCnt[i] = cnt ;
        }
        return prefixCnt ;
    }
};