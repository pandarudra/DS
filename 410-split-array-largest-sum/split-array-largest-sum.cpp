#define all(v) begin(v),end(v)
class Solution {
private:
    bool cntK(int mid , vector<int>& nums , int k){
        
        int s = 0 ;
        int cnt = 1 ;

        for(auto &num : nums){
            if(s + num > mid){
                cnt++ ;
                s = num ;
                if(cnt > k)return false ;
            }else{
                s += num ;
            }
            
        }
        return true ;
    }
public:
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(all(nums)) ;
        int high = accumulate(all(nums) , 0) ;

        while(low <= high){
            int mid = high +(low - high) / 2 ;
            if(cntK(mid , nums , k)){
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }
        return low ;
    }
};