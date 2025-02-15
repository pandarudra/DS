class Solution {
private:
    // bool sumD(int n , int sq){
        
    // }
    vector<int> precompute = {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000};
    // void calc(){
    //     for(int i = 1 ; i <= 1000 ; i++){
    //         if(sumD(i , i * i)){
    //             precompute.push_back(i) ;
    //         }
    //     }
    // }
public:
    // Solution(){
    //     calc() ;
    // }
    int punishmentNumber(int n) {
        int  s = 0 ;
        for(int i  = 0 ; i < precompute.size() ; i++){
            if(precompute[i] > n)break ;
            s += (precompute[i] * precompute[i]) ;
        }
        return s ;
    }
};