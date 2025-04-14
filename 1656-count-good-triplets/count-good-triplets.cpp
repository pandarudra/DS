class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0 ;
        int n = arr.size() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    int u = abs(arr[i] - arr[j]) ;
                    int v = abs(arr[j] - arr[k]) ;
                    int w = abs(arr[k] - arr[i]) ;
                    if(u <= a && v <= b && w <= c){
                        cnt++ ;
                    }
                }
            }
        }
        return cnt ;
    }
};