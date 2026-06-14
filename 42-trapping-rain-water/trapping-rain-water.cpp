#define all(v) (v).begin(),(v).end()
#define pii pair<int , int>
class Solution {
public:
    int trap(vector<int>& height) {
        int trapped = 0 ;
        int n = height.size() ;
        
        int left = 0 , right = n - 1 ;
        int mxleft = 0 , mxright = 0 ;

        while(left <= right) {
            if(height[left] <= height[right]) {
                if(mxleft <= height[left]) {
                    mxleft = height[left] ;
                }else {
                    trapped += (mxleft - height[left]) ;
                }
                left++ ;
            }else {
                if(mxright < height[right]) {
                    mxright = height[right] ;
                }else {
                    trapped += (mxright - height[right]) ;
                }
                right-- ;
            }
        }

        return trapped ;
    }
};