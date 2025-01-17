class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
      
        int xorr = 0 ;
        for(auto &it : derived){
            xorr = xorr ^ it ;
        }
        if(xorr == 0)return true ;
        return false ;
    }
};