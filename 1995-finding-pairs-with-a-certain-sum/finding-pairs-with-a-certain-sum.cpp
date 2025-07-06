#define all(v) (v).begin(),(v).end()
#define umap unordered_map
class FindSumPairs {
private:
     umap<int , int> tMap ;
     vector<int> Ovector , Tvector ; 
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        Ovector.assign(all(nums1)) ;
        Tvector.assign(all(nums2)) ;

        int N = nums2.size() ;
        for(int i = 0 ; i < N ; i++) {
            tMap[nums2[i]]++ ;
        }
    }
    
    void add(int index, int val) {
        tMap[Tvector[index]]-- ;
        Tvector[index] = Tvector[index] + val ;
        tMap[Tvector[index]]++ ;
    }
    
    int count(int tot) {
        int cnt = 0 ;
        for(auto& e : Ovector) {
            if(tMap[tot - e] > 0) {
                cnt += tMap[tot - e] ;
            }
        }
        return cnt ;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */