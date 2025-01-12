class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n) ;
        for(int i = 0 ; i < n ; i++)v[i] = i+1 ;
        int  t = n ;
        int i = 0 ;
        while(t != 1){
            i = (i+k-1) % t ;
            v.erase(v.begin() + i) ;
            t-- ;
        }
        return v[0] ;
    }
};