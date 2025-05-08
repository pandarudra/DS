#define all(v) begin(v),end(v)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(all(g)) ;
        sort(all(s)) ;
        int cnt = 0 ;
        int si = 0 , gi = 0 ;
        while(gi < g.size() && si < s.size()) {
            if(s[si] >= g[gi]) {
                cnt++ ;
                si++ ;
                gi++ ;
            }else{
                si++ ;
            }
        }        
        return cnt ;
    }
};