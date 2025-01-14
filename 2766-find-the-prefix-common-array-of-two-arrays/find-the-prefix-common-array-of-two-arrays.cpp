class Solution {
public:
    int cntEquals(unordered_set<int>& a , unordered_set<int>& b){
        int  cnt = 0 ;
        for(auto &it : a){
            if(b.count(it)){
                cnt++ ;
            }
        }
        return  cnt ;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> sA , sB ;
        int n = A.size() ;
        vector<int> prefixCnt(n , 0) ;
        for(int i = 0 ; i < n  ; i++){
            sA.insert(A[i]) ;
            sB.insert(B[i]) ;
            prefixCnt[i] = cntEquals(sA , sB) ;
        }
        return prefixCnt ;
    }
};