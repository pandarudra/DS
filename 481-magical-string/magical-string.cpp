class Solution {
public:
    int magicalString(int n) {
        string init = "122" ;
        if(n <= 3) return 1 ;
        int cnt = 1 ;
        string alt = "1" ;
         for (int i = 2; init.length() < n; i++) {
            int f = (init[i] == '2') ? 2 : 1;
            init += string(f, alt[0]);  
            
            if (alt == "1") {
                cnt += min(f, n - (int)init.length() + f); 
                alt = "2";
            } else {
                alt = "1";
            }
        }
        
        return cnt ;
    }
};