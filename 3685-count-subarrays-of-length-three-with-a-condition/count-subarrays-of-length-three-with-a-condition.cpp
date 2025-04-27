class Solution {
private:
    bool window(vector<int>& nums , int i , int j){
        double u = (1.0) * nums[i] ;
        double v = (1.0) * nums[j] ;
        double w = (1.0) * nums[i + 1] ;
        return (u + v) == ((1.0) * w / 2) ;
    }
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size() , cnt = 0 ;
        for(int i = 0 ; i <= n - 3 ; i++){
            if(window(nums , i , i + 2)){
                cnt++ ;
            }
        }
        return cnt ;
    }
};