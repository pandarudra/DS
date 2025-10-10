class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int N = energy.size() ;
        int mx = INT_MIN ;
        
        for(int i = N - 1 ; i >= 0 ; i--) {
            int nextRecentIndex = i + k ;
            if(nextRecentIndex < N) energy[i] += energy[nextRecentIndex] ;
            mx = max(mx , energy[i]) ;
        }

        return mx ;
    }
};