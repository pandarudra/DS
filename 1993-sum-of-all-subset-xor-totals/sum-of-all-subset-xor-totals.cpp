class Solution {
private:
    void sub(vector<int>& nums , int  i , int& s , int x , int n){
        if(i >= n){
            s += x ;
            return ;
        }
        x ^= nums[i] ;
        sub(nums , i + 1 , s , x , n) ;
        x ^= nums[i] ;
        sub(nums , i + 1 , s , x , n) ;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int s = 0 ;
        int n = nums.size() ;
        sub(nums , 0 , s , 0 , n) ;
        return s ;
    }
};