class Solution {
public:
    int Getnum(deque<int>& bit){
        int n = bit.size() ;
        int num = 0 ;
        int mul = 1 ;
        for(int i = n-1 ; i >= 0 ; i--){
            if(bit[i]){
                num += mul ;
            }
            mul *= 2 ;
        }
        return num ;
    }
    deque<int> Getbitvector(int num1){
        deque<int> bit ;
        int t = num1 ;
        while(t > 0){
            bit.push_back(t % 2) ;
            t /= 2 ;
        }
        reverse(bit.begin(),bit.end()) ;
        return bit ;
    }
    int minimizeXor(int num1, int num2) {
        int sb2 = __builtin_popcount(num2) ;
        
        deque<int> bit = Getbitvector(num1) ;
        for(int i = 0 ; i < bit.size() ; i++){
            if(bit[i] == 1 && sb2 > 0){
                sb2-- ;
            }else if(bit[i] == 1){
                bit[i] = 0 ;
            }
        }
        int i = bit.size() - 1 ;
        while(i >= 0 && sb2 > 0){
            if(bit[i] == 0){
                bit[i] = 1 ;
                sb2-- ;
            }
            i-- ;
        }

        while(sb2 > 0){
            bit.push_front(1) ;
            sb2 -- ;
        }
        int x = Getnum(bit) ;

        return x ;
    }
};