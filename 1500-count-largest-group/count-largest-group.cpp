#define umap unordered_map
class Solution {
private:
    int sumDgt(int n){
        int s = 0 ;
        while(n > 0){
            s += (n % 10) ;
            n /= 10 ;
        }
        return s ;
    }
public:
    int countLargestGroup(int n) {
        umap<int , int> mp ;
        int mx = 0 ;
        for(int i = 1 ; i <= n ; i++){
            int k = sumDgt(i) ;
            mp[k] ++ ;
            mx = max(mx , mp[k]) ;
        }
        
        int cnt = 0 ;
        for(auto& [k , v] : mp){
            if(v == mx){
                cnt++ ;
            }
        }
        return cnt ;
    }
};