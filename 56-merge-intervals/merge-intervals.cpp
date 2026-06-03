#define all(v) (v).begin(),(v).end()
#define pb push_back
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged ;
        sort(all(intervals)) ;
        int n = intervals.size() ;
        int st = intervals[0][0] , end = intervals[0][1] ;
        for(auto i : intervals) {
            int curSt = i[0] , curEnd = i[1] ;
            if(curSt <= end) {
                end = max(end , curEnd) ;
            }else {
                merged.pb({st , end}) ;
                st = curSt , end = curEnd ;
            }
        }
        merged.pb({st , end}) ;
        return merged ;
    }
};