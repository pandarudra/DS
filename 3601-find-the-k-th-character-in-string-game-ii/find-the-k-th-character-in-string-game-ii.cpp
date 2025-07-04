typedef long long ll ;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
       ll length = 1 ;
       vector<ll> Lvect ;

       for(auto& op : operations) {
        length *= 2 ;
        Lvect.push_back(length) ;
        if(length >= k) break ;
       }

       ll t = 0 ;
       ll N = Lvect.size() ;
       
       for(ll i = N - 1 ; i >= 0 ; i--) {
        ll L = Lvect[i] ;
        ll H = L / 2 ;

        if(k > H) {
            k -= H ;
            if(operations[i] == 1) t++ ;
        }
       }

       char ch = 'a' ;
       ch = (ch - 'a' + t) % 26 + 'a' ;

       return ch ;
    }
};