class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m ;
        int del = (n * (n + 1) / 2) - (m * k * (k + 1)) ;
        return del ;
    }
};