#define uset unordered_set
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size() ;
        uset <int> s(all(arr)) ;
        int mx = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int curr = arr[j] ;
                int next = arr[i] + arr[j] ;
                int length = 2 ;

                while(s.count(next)){
                    int t = next ;
                    next += curr ;
                    curr = t ;
                    mx = max(mx , ++length) ;
                }
            }
        }
        return mx ;
    }
};