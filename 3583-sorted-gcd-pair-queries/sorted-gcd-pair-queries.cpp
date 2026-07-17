#define umap unordered_map
class Solution {
    int binarySearch(long long q , vector<long long>& v) {
        int lo = 1 , hi = v.size() - 1 ;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2 ;
            if(v[mid] >= q) hi = mid - 1 ;
            else if(v[mid] < q) lo = mid + 1 ;
        }
        return lo ;
    }
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = (int) nums.size() ;
        
        long long mx = *max_element(nums.begin() , nums.end()) ;
        
        vector<long long> _map(mx + 1) ;
        
        
        for(int i = 0 ; i < n ; i++) _map[nums[i]]++ ;


        vector<long long> cntDiv(mx + 1) ;

        for(int i = 1 ; i <= mx ; i++) {
            for(int j = i ; j <= mx ; j += i) {
                cntDiv[i] += _map[j] ;
            }
        }

        vector<long long> cntPair(mx + 1) ;

        for(int i = 1 ; i <= mx ; i++) {
            cntPair[i] = cntDiv[i] * (cntDiv[i] - 1) / 2 ;
        }



        vector<long long> exact(mx + 1);

        
        for(int i = mx ; i >= 1 ; i--) {
            exact[i] = cntPair[i] ;
            for(int j = 2 * i ; j <= mx ; j += i) {
                exact[i] -= exact[j] ;
            }
        }


        for(int i = 2 ; i <= mx ; i++) {
            exact[i] += exact[i - 1] ;
        }

        vector<int> ans ;
        for(auto q : queries) {
            int x = binarySearch(q + 1, exact) ;
            ans.push_back(x) ;
        }

        return ans ;

    }
};


// cnt divisables
// cnt pairs
// sort accn to key of map
// suffix substraction from backward
// prefix sum from forward
// binary search
// get the value
