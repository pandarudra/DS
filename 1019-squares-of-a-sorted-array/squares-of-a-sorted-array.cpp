#define all(v) (v).begin(),(v).end()
class Solution {
    void transform(vector<int>& b , vector<int>& a , int k) {
        int left = k - 1 ;
        int right = k ;
        int t = 0 , n = a.size();
        while(t < n) {
            int u = left >= 0 ? abs(a[left]) : INT_MAX ;
            int v = right < n ? a[right] : INT_MAX ;
            if(u < v) {
                b[t] = u ;
                left-- ;
            } else {
                b[t] = v ;
                right++ ;
            }
            t++ ;
        }

    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() ;
        int point = 0 ;
        while(point < n && nums[point] < 0) point++ ;
        
        vector<int> ans(all(nums)) ;
        if(point != 0) transform(ans , nums , point) ;

        for(auto& x : ans) x = x * x ;

        return ans ;
    }
};