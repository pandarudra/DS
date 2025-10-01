class Solution {
private:
    int f(int x , int y) {
        if(x < y) return x ;
        int m = x / y ;
        int b = y * m ;
        int a = x - b + m ;
        return b + f(a , y) ;
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return f(numBottles , numExchange) ;
    }
};