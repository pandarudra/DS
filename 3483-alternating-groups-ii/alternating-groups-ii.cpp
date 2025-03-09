class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size() ;
        int cnt = 0 ;
        int alt = 1 ;
        int prev = colors[0] ;
        for(int i = 1 ; i < n + k - 1 ; i++){
            if(colors[i % n] == prev){
                prev = colors[i % n] ;
                alt = 1 ;
            }else{
                alt++ ;
                if(alt >= k){
                    cnt++ ;
                }
                prev = colors[i % n] ;
            }
        }
        return cnt ;
    }
};