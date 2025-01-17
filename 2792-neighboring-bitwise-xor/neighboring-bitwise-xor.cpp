class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size() ;
    
        int cntZero = 0 ;
        for(auto &it : derived){
            if(it == 0){
                cntZero ++ ;
            }
        }
        if(cntZero == n)return true ;
        if(n % 2 == 0 && cntZero % 2 == 0)return true ;
        if(n % 2 != 0 && cntZero % 2 != 0)return true ;
        if(cntZero == 0){
            if(n % 2 == 0)return true ;
            else return false ;
        }
        return false ;
    }
};