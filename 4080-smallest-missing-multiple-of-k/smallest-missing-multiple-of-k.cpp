class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st ;
        int mx = 1 ;
        
        for(auto x : nums) {
            st.insert(x) ;
            mx = max(mx , x) ;
        } 
        for(int i = 1 ; i <= mx / k ; i++) {
            if(!st.count(k * i)) {
                return k * i ;
            }
        }        

        return k * (mx / k + 1) ;
    }
};