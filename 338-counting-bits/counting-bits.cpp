class Solution {
private:
    int cntBit(int n){
        return __builtin_popcount(n) ;
    }
public:
    vector<int> countBits(int n) {
        vector <int> res(n + 1) ;
        for(int i = 0 ; i <= n ; i++){
            res[i] = cntBit(i) ;
        }
        return res ;
    }
};