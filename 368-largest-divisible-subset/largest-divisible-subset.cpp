#define all(v) (v).begin(),(v).end()
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(all(nums)) ;
        int N = nums.size() ;
        vector<int> dp(N , 1) ;
        vector<int> hash(N , 1) ;

        for(int i = 0 ; i < N ; i++) {
            hash[i] = i ;
            for(int j = 0 ; j < i ; j++) {
                if(nums[i] % nums[j] == 0 && 1 + dp[j] >= dp[i]) {
                    dp[i] = 1 + dp[j] ;
                    hash[i] = j ;
                }
            }
        }

        int mxLen = -1 ;
        int LastInd = -1 ;

        for(int i = 0 ; i < N ; i++) {
            if(dp[i] > mxLen) {
                mxLen = dp[i] ;
                LastInd = i ;
            }
        }

        vector<int> lds ;
        lds.push_back(nums[LastInd]) ;

        while(hash[LastInd] != LastInd) {
            LastInd = hash[LastInd] ;
            lds.push_back(nums[LastInd]) ;
        }

        return lds ;
    }
};
