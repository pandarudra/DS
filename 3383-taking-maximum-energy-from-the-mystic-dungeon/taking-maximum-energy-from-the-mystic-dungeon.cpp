#define all(v) (v).begin(),(v).end()
#define pb push_back
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int N = energy.size() ;
        
        for(int i = N - 1 ; i >= 0 ; i--) {
            int nextIndex = i + k ;
            if(nextIndex < N) energy[i] += energy[nextIndex] ;
        }

        return *max_element(all(energy)) ;
    }
};