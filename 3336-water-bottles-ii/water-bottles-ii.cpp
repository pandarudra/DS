class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int cnt = 0 , empty = 0 ;

        while(true) {
            cnt += numBottles ;
            empty += numBottles ;
            numBottles = 0 ;
            while(empty >= numExchange) {
                empty -= numExchange ;
                numExchange++ ;
                numBottles++ ;
            }
            if(numBottles == 0 && empty < numExchange) break ;
        }
        return cnt ;
    }
};