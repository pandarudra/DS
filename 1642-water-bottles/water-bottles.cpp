class Solution {
private:
    int f(int x , int y) {
        int canDrink = 0 ;
        
        while(x >= y) {
            int m = x / y ;
            int b = y * m ;
            x = x - b + m ;
            canDrink += b ;
        }
     
        return x + canDrink ;
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return f(numBottles , numExchange) ;
    }
};