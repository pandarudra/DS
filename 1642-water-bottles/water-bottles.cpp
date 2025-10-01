class Solution {
private:
    int f(int x , int y) {
        int canDrink = 0 ;
        
        while(x >= y) {
            int m = x / y ;
            int b = y * m ;
            int a = x - b + m ;
            canDrink += b ;
            x = a ;
        }
     
        return x + canDrink ;
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return f(numBottles , numExchange) ;
    }
};