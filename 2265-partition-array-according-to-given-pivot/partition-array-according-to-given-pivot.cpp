#define all(v) (v).begin(),(v).end()
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less , equal , greater ;
        for(auto& it : nums){
            if(it < pivot){
                less.push_back(it) ;
            }else if(it > pivot){
                greater.push_back(it) ;
            }else{
                equal.push_back(it) ;
            }
        }
        less.insert(less.end() , all(equal)) ;
        less.insert(less.end() , all(greater)) ;
        return less ;
    }
};