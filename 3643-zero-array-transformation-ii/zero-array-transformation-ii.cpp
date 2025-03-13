class Solution {
private:
    bool valid(vector<int>& nums , vector<vector<int>>& q , int mid){
        int n = nums.size() ;
        vector <int> d(n + 1 , 0) ;

        for(int i = 0 ; i < mid ; i++){
            int u = q[i][0] ;
            int v = q[i][1] ;
            int w = q[i][2] ;
            d[u] += w ;
            d[v + 1] -= w ;
        }

        int s = 0 ;

        for(int i = 0 ; i < n ; i++){
            s += d[i] ;
            if(s < nums[i]){
                return false ;
            }
        }

        return true ;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0 , high = queries.size() ;

        if(!valid(nums , queries , high))return -1 ;

        while(low <= high){
            int mid = low + (high - low) / 2 ;
            if(valid(nums , queries , mid)){
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }

        return low ;
    }
};