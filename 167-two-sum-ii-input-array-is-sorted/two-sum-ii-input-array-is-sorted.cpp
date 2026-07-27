class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() ;
        int left = 0 , right = n - 1 ;

        while(left < right) {
            int v = numbers[left] + numbers[right] ;
            if(v == target) return {left + 1 , right + 1} ;
            else if(v < target) left++ ;
            else right-- ;
        }

        return {-1 , -1} ;
    }
};