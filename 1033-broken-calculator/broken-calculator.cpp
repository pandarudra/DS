class Solution {
private:
    int findSteps(int s , int t) {
        if(s == t) return 0 ;
        if(t < s) return s - t ;
        int steps = 0 ;
        while(t > s){
            if(t % 2 != 0) {
               steps++ ;
               t++ ;
            }
            t /= 2 ;
            steps++ ;
        }
        
        return (s - t) + steps ;
    }
public:
    int brokenCalc(int startValue, int target) {
        return findSteps(startValue , target) ;
    }
};