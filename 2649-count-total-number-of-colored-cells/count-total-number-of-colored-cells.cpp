#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        return (2LL * n * n) - (2LL * n) + 1 ;
    }
};