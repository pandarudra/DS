#define all(v) (v).begin(),(v).end()
#define pb push_back
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int N = energy.size() ;
        
        for(int i = N - 1 ; i >= 0 ; i--) {
            int nextRecentIndex = i + k ;
            if(nextRecentIndex < N) energy[i] += energy[nextRecentIndex] ;
        }

        return *max_element(all(energy)) ;
    }
};