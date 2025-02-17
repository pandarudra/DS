#define uset unordered_set
#define umap unordered_map
class Solution {
private:
    void helper(umap<char , int>& freq , string ds , int n , uset<string>& letters){
        
        if(!ds.empty())letters.insert(ds) ;
        
        for(auto& [ch , cnt] : freq){
            if(cnt > 0){
                cnt-- ;
                helper(freq , ds + ch , n , letters) ;
                cnt++ ;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.length() ;
        uset<string> letters ;
        umap<char , int> freq ;
        for(auto &ch : tiles) freq[ch]++ ;

        helper(freq , "" , n , letters) ;

        return letters.size() ;
    }
};