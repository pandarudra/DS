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
        for(int i = 1 ; i <= n ; i++){
            mp[sumDgt(i)] ++ ;
        }
        int mx = 0 ;
        for(auto& [k , v] : mp){
            mx = max(mx , v) ;
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