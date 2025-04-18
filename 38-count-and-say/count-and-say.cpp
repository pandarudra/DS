class Solution {
private:
    string RLE(string s){
        int n = s.length() ;
        int i = 1 ;
        string rle = "" ;
        int freq = 1 ;
        char ch = s[0] ;
        while(i < n){
            if(s[i] == ch){
                freq++ ;
            }else{
                rle += to_string(freq) ;
                rle.push_back(ch) ;
                freq = 1 ;
                ch = s[i] ;
            }
            i++ ;
        }
        rle += to_string(freq) ;
        rle.push_back(ch) ;
        
        return rle ;
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1" ;
        return RLE(countAndSay(n - 1)) ;
    }
};