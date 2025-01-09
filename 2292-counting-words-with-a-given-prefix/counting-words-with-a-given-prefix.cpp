struct trie{
    trie* links[26];
    bool end =  false;

    bool contains(char ch){
        return links[ ch - 'a' ] != nullptr;
    }

    trie* gofurther(char ch){
        return links[ ch - 'a' ];
    }

    void put(char ch){
        links[ ch - 'a' ] = new trie();
    }
};
class Solution {
private:
    trie* root;
    
    

    void insert(string  word){
        trie* dummy = root;

        for(int i = 0; i < word.length() ; i++){
            if(!dummy->contains(word[i])){
                dummy->put(word[i]);
            }
            dummy = dummy->gofurther(word[i]);
        } 

        dummy->end = true;

    }

    bool search(string prefix){
        trie* dummy = root;
        for(int i = 0; i < prefix.length() ; i++){
            if(dummy->contains(prefix[i])){
                dummy = dummy->gofurther(prefix[i]);
            }else{
                return false;
            }
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for( auto &str : words ){
            root = new trie();
            insert(str);
            if(search(pref)){
                cnt++;
            }
        }
        return cnt;
    }
};