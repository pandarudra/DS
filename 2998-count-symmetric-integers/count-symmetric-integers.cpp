class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0 ;
        for(int i = low ; i <= high ; i++){
            int nd = (int) log10(i) + 1 ;
            if(nd % 2 == 0){
                if(i >= 1 && i <= 100 && i % 11 == 0){
                    cnt++ ;
                }else if(i >= 1000 && i < 10000){
                    int right = (i % 10) + ((i % 100) / 10) ;
                    int left = ((i % 1000) / 100) + (i / 1000) ;
                    if(left == right){
                        cnt++ ;
                    }
                }
            }
        }
        return cnt ;
    }
};