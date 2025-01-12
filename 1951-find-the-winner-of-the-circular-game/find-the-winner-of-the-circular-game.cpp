class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q ;
        for(int i = 1 ;i <= n ; i++)q.push(i) ;

        while(q.size() != 1){
            int cnt = 0 ;
            while(cnt != k-1){
                int in = q.front() ;
                q.pop() ;
                q.push(in) ; 
                cnt ++ ;
            }
            q.pop() ;
        }
        return q.front() ;
    }
};