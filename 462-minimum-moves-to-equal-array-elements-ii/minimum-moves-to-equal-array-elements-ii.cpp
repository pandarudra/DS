class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        int mid  = (nums[0] + nums[n-1]) / 2 ;
        int  epsilone = 0 ;
        if(n & 1){
            epsilone = nums[n/2] ;
        }else{
            epsilone = (nums[n/2] + nums[(n-1)/2]) / 2 ;
        }
        int moves = 0 ;
        for(auto &it : nums) {
            moves += abs(it - epsilone) ;
        }
        return moves ;
    }
};