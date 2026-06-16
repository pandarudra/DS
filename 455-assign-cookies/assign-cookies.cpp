#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(all(g)) ;
        sort(all(s)) ;
        
        int gn = g.size() ;
        int sn = s.size() ;
        
        int i = 0 , j = 0 ;
        int mx = 0 ;
        
        while(i < gn) {
            int need = g[i] ;
            int hv = j < sn ? s[j] : INT_MIN ;
            if(need <= hv) {
                mx++ ;
                i++ ;
            }
            if(j < sn) j++ ;
            else break ;
        }
        return mx ;
    }
};