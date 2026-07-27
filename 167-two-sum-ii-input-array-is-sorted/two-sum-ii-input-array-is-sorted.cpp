class Solution {
    int getPos(vector<int>& v , int l , int h , int t) {
        while(l <= h) {
            int m = l + (h - l) / 2 ;
            if(v[m] == t) return m ;
            else if(v[m] < t) l = m + 1 ;
            else h = m - 1 ;
        }
        return -1 ;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() ;

        for(int i = 0 ; i <= n - 1 ; i++) {
            int x = i ;
            int y = getPos(numbers , i + 1 , n - 1 , target - numbers[i]) ;
            if(y != -1) return {x + 1 , y + 1} ;
        }

        return {-1 , -1} ;
    }
};