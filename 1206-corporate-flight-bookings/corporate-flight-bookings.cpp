class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector <int> d(n + 1 , 0) ;
        for(auto& b : bookings){
            int u = b[0] ;
            int v = b[1] ;
            int w = b[2] ;
            d[u - 1] += w ;
            d[v] -= w ;
        }
        vector <int> res(n) ;
        for(int i = 0 ; i < n ; i++){
            d[i] = d[i] + (i > 0 ? d[i - 1] : 0) ;
            res[i] = d[i] ;
        }
        return res ;
    }
};