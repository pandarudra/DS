#define all(v) (v).begin(),(v).end()
#define uset unordered_set


struct VectorHash {
    size_t operator()(const vector<int>& vec) const {
        size_t hash = 0;
        for (int num : vec) {
            hash ^= hash * 31 + std::hash<int>()(num);
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(all(nums));
        int n = nums.size() ;
        uset<vector<int>,VectorHash> container ;
        vector<vector<int>> sol ;
        for(int i = 0 ; i < n ; i++){
            int a = -nums[i] ;
            int low = i + 1 , high = n - 1 ;
            while(low < high){
                if(nums[low] + nums[high] == a){
                    vector<int> v = {nums[i],nums[low],nums[high]} ;
                    sort(all(v)) ;
                    if(!container.count(v)){
                        sol.push_back(v) ;
                        container.insert(v) ;
                    }
                    low ++ ;
                    high -- ;
                }
                if(nums[low] + nums[high] > a){
                    high -- ;
                }else if(nums[low] + nums[high] < a){
                    low ++ ;
                }
                
            }
        }
        return sol ;
    }
};