class Solution {
private:
    int f(int x , int y) {
        int canDrink = 0 ;
        
        while(x >= y) {
            int m = x / y ;
            x -= (m * (y - 1)) ;
            canDrink += (m * y) ;
        }
     
        return x + canDrink ;
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return f(numBottles , numExchange) ;
    }
};