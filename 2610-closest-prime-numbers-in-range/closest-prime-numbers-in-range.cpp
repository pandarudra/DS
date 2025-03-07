class Solution {
    vector<int> sieve ;
public:
    Solution() : sieve(1000001 , 1) {
        sieve[0] = sieve[1] = 0 ;
        for(int i = 2 ; i * i <= 1000000 ; i++){
            if(sieve[i] == 1){
                for(int j = i * i ; j <= 1000000 ; j += i){
                    sieve[j] = 0 ;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes ;
        for(int i = left ; i <= right ; i++){
            if(sieve[i]){
                primes.push_back(i) ;
            }
        }
        if(primes.size() < 2){
            return {-1 , -1} ;
        }
        int d = INT_MAX ;
        vector<int> res = {-1 , -1} ;
        for(int i = 1 ; i < primes.size() ; i++){
            if(primes[i] - primes[i - 1] < d){
                d = primes[i] - primes[i - 1] ;
                res[0] = primes[i - 1] ;
                res[1] = primes[i] ;
            }
        }
        return res ;
    }
};