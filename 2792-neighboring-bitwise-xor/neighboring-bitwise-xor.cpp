#define all(v) (v).begin(),(v).end()
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
      int s = accumulate(all(derived),0) ;
      return s % 2 == 0 ;
    }
};