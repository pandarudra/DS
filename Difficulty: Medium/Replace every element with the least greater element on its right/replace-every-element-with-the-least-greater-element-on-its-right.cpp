//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> LG(n , -1) ;
        set<int> bst ;
        for(int i  = n - 1 ; i >= 0 ; i--) {
            auto it = bst.upper_bound(arr[i]);
            if (it != bst.end()) {
                LG[i] = *it;
            }
            bst.insert(arr[i]);
        }
        return LG ;
    }
};