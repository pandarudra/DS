#define umap unordered_map
class Solution {
private:
    // unequal string's map
    umap<string , int> unequal ;
    // equal string's map
    umap<string , int> equal ;

public:
    int longestPalindrome(vector<string>& words) {

        // store frequency
        for(auto& word : words) {
            if(word[0] == word[1]) {
                equal[word]++ ;
            }else {
                unequal[word]++ ;
            }
        }    

        int length = 0 ;

        // 1st go for unequal strings 
        for(auto& word : words) {
            string rev = "" ;
            rev += word[1] ;
            rev += word[0] ;

            if(unequal.count(word) && unequal.count(rev)) {
                unequal[rev]-- ;
                length += 2 ;
                unequal[word]-- ;
            }else if(unequal[word] > 0) {
                unequal[word]-- ;
            }

            if(unequal[word] == 0) {
                unequal.erase(word) ;
            }

            if(unequal[rev] == 0) {
                unequal.erase(rev) ;
            }
        }

        // now go for equal strings
        // fL => Flag bit 

        int mxLen = 0 , fL = 0 ;
        for(auto& [k , v] : equal) {
            if(v == 1 && fL == 0) {
                mxLen ++ ;
                fL = 1 ;
            }else if(v > 1) {
                if(v % 2 != 0) {
                    mxLen += (v - 1) ;
                    equal[k] -= (v - 1) ;
                }else {
                    mxLen += v ;
                    equal[k] -= (v) ;
                }
            }

           
        }

        // if Flag bit still 0 we can add a single equal string
        if(fL == 0 && !equal.empty()) {
            for(auto& [k , v] : equal) {
                if(v > 0) {
                    mxLen++ ;
                    break ;
                }
            }
        }

        // length = 2 * no. of strings
        length *= 2 ;
        mxLen *= 2 ;

        return mxLen + length ;
    }
};