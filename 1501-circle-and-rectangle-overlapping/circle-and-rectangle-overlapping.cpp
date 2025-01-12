class Solution {
public:
    int dist(int x , int x1 , int y , int y1){
        return ((x-x1)*(x-x1) + (y-y1)*(y-y1)) ;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = max(x1 , min(x2 , xCenter)) ;
        int y = max(y1 , min(y2 , yCenter)) ;
        int  mini = dist(x ,xCenter , y , yCenter) ;

        return mini <= radius * radius ;
    }
};