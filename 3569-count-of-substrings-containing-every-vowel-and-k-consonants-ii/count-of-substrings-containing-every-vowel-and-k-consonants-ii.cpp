#define ll long long 
#define umap unordered_map
#define uset unordered_set
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        ll cnt = 0 ;
        ll n = word.length() ;
        umap <char , int> mp ;
        uset <char> vowel = {'a' , 'e' , 'i' , 'o' , 'u'} ; 
        ll c = 0 ;
        ll v = 0 ;
        ll left = 0 ;
        ll extra_left = 0 ;

        for(ll right = 0 ; right < n ; right++){
            if(!vowel.count(word[right])){
                c++ ;
            }else{
                if(mp[word[right]] == 0) v++ ;
                mp[word[right]]++ ;
            }

            while(c > k){
                char tmp = word[left++] ;
                if(!vowel.count(tmp)){
                    c-- ;
                }else{
                    if(mp[tmp] > 0){
                        mp[tmp]-- ;
                    }
                    if(mp[tmp] == 0){
                        mp.erase(tmp) ;
                        v-- ;
                    }
                }
                extra_left = 0 ; 
            }

            while(c == k && v == 5 && mp.count(word[left]) && mp[word[left]] > 1){
                extra_left++ ;
                mp[word[left]]-- ;
                left++ ;
            }

            if(c == k && v == 5){
                cnt += (1 + extra_left) ;
            }
        }
        return cnt ;
    }
};