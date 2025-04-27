#define umap unordered_map
class Solution {
private:
    umap<int , int> memo ;
    int dp(vector<int>& v , int n , int k){
        if(n == 0) return 0 ;
        if(memo.count(n)) return memo[n] ;

        int mx = 0 ;
        for(int i = 2 ; i < k ; i++){
            int left = (n - i >= 0) ? dp(v , n - i , k) + v[n - i] : INT_MIN ;
            mx = max(mx , left) ; 
        }

        return memo[n] = mx ;
    }

    int cntMax(vector<int>& v){
        int n = v.size() ;
        if(n == 0) return 0 ;
        int left = dp(v , n - 1 , n) + v[n - 1] ;
        int right = (n - 2 >= 0) ? dp(v , n - 2 , n) + v[n - 2] : INT_MIN ;
        return max(left , right) ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;

        if(n == 1) return nums[0] ;
        
        vector<int> t1 (nums.begin() + 1 , nums.end()) ;
        vector<int> t2 (nums.begin() , nums.end() - 1) ; 

        int left = cntMax(t1) ;
        memo.clear() ;
        int right = cntMax(t2) ;

        return max(left , right) ;
    }
};