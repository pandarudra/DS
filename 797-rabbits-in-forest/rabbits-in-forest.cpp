#define umap unordered_map
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int mn = 0 ;
        umap<int , int> mp ;
        for(auto& it : answers){
            if(it == 0){
                mn++ ;
            }else if(it != 0 && mp[it] == it + 1){
                mp.erase(it) ;
                mn += (it + 1) ;
            }
            if(it != 0) {
                mp[it]++ ;
            }
        }

        for(auto& [k , v] : mp){
            mn += (k + 1) ;
        }

        return mn ;
    }
};