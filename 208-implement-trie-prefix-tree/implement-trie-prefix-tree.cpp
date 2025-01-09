struct trie{
    trie *links[26];
    bool flag = false;

    bool contain(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch ){
        links[ch-'a']=new trie();
    }

    trie* gofurther(char ch){
        return links[ ch - 'a' ];
    }
};
class Trie {
    trie *root;
public:
    Trie() {
        root = new trie();
    }
    
    void insert(string word) {
        trie* node=root;
        for(int i = 0; i < word.length() ; i++){
            if(!node->contain(word[i])){
                node->put(word[i]);
            }
            node=node->gofurther(word[i]);
        }
        node->flag=true;
    }
    
    bool search(string word) {
        trie* node=root;

        for(int i = 0 ; i < word.length() ; i++){
            if(node->contain(word[i])){
                node = node->gofurther(word[i]);
            }else{
                return false;
            }
        }
        
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        
        trie* node = root;
        for(int i = 0 ; i < prefix.length() ; i++ ){
            if(node->contain(prefix[i])){
                node = node->gofurther(prefix[i]);
            }else{
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */