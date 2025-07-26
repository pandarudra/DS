// User function Template for C++

class Solution {
  private:
    const int mod = 1e9 + 7 ;
    int nPr(int n , int r) {
        int P = 1 ;
        for(int i = n ; i > n - r ; i--) {
            P = (1LL * P * i) % mod ;
        }
        return P % mod ;
    }
  public:
    int permutationCoeff(int n, int k) {
        return nPr(n , k) % mod ;
    }
};
