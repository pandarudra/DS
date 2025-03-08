class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mn = 1e9 ;
        int n = blocks.length() ;
        for(int i = 0 ; i <= n - k ; i++){
            int op = 0 ;
            for(int j = i ; j  < i + k ; j++){
                if(blocks[j] == 'W'){
                    op++ ;
                }
            }
            mn = min(op , mn) ;
        }
        return mn ;
    }
};