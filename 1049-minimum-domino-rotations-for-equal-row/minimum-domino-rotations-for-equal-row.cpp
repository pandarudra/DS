#define umap unordered_map
#define all(v) (v).begin(),(v).end()
#define ipair pair<int , int>
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size() ;
        umap<int , int> t_mp , b_mp ;

        for(auto& it : tops) t_mp[it] ++ ;
        for(auto& it : bottoms) b_mp[it] ++ ;

        
        ipair mx1 = *max_element(all(t_mp) , [](auto const& a , auto const& b){
            return a.second < b.second ;
        }) ;

        ipair mx2 = *max_element(all(b_mp) , [](auto const& a , auto const& b){
            return a.second < b.second ;
        }) ;

        int m1 = mx1.first ;
        int m2 = mx2.first ;
        
        int mn1 = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(m1 == tops[i]) continue ;
            if(m1 == bottoms[i]){
                mn1++ ;
            } else {
                mn1 = -1 ;
                break ;
            }
        }

        int mn2 = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(m2 == bottoms[i]) continue ;
            if(m2 == tops[i]){
                mn2++ ;
            } else {
                mn2 = -1 ;
                break ;
            }
        }

        if(mn1 == -1 && mn2 == -1) return -1 ;
        if(mn1 == -1) return mn2 ;
        if(mn2 == -1) return mn1 ;

        return min(mn1 , mn2) ;
    }
};