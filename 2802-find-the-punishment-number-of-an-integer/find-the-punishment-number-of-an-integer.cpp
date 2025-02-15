class Solution {
private:
    bool canBe(string sq , int n){
        if(sq == "" && n == 0)return true ;
        if(n < 0) return false ;

        for(int i = 0 ; i < sq.length() ; i++){
            string left = sq.substr(0 , i + 1) ;
            string right = sq.substr(i + 1) ;
            int del = stoi(left) ;
            if(canBe(right , n - del))return true ;
        }
        return false ;
    }
    vector<int> precompute ;
    void  calc(){
        for(int i = 1 ; i <= 1000 ; i++){
            if(canBe(to_string(i * i) , i)){
                precompute.push_back(i) ;
            }
        }
    }
    public:
    Solution(){
        calc() ;
    }
    int punishmentNumber(int n) {
        int  s = 0 ;
        for(int i  = 0 ; i < precompute.size() ; i++){
            if(precompute[i] > n)break ;
            s += (precompute[i] * precompute[i]) ;
        }
        return s ;
    }
};