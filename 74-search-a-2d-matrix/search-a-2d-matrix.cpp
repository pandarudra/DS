class Solution {
    int bSearch(vector<int>& v , int n , int t) {
        int low = 0 , high = n - 1 ;
        while(low <= high) {
            int mid = low + (high - low) / 2 ;
            if(v[mid] == t) return mid ;
            else if(v[mid] > t) high = mid - 1 ;
            else low = mid + 1 ;
        }
        return high ;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size() ;


        vector<int> fcol(n) ;


        for(int i = 0 ; i < n ; i++) fcol[i] = matrix[i][0] ;

        int rei = bSearch(fcol , n , target) ;

        
        if(rei < 0) return false ;

        int re = bSearch(matrix[rei] , m , target) ;

      
        if(re > m || re < 0) return false ;

        return matrix[rei][re] == target ;
    }
};