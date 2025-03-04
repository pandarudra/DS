#include <unordered_set>

#define uset unordered_set

class Solution {
public:
    bool checkPowersOfThree(int n) {
        uset<int> s;
        
        while (n > 0) {
            int power = 1, exponent = 0;
            
            // Find the largest power of 3 that is ≤ n using integer arithmetic
            while (power * 3 <= n) {
                power *= 3;
                exponent++;
            }
            
            // If the exponent is already used, return false
            if (s.count(exponent)) {
                return false;
            }
            
            s.insert(exponent);
            n -= power;  // Subtract the found power from n
        }
        
        return true;
    }
};
