class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size() ;
        vector<int> vis(n , 0) , indegree(n , 0) , chainLength(n , 0) ;
        for(auto fav : favorite){
            indegree[fav]++ ;
        }

        queue<int> q ;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            int fav = favorite[node] ;
            vis[node] = 1 ;
            chainLength[fav] = chainLength[node] + 1 ;
            indegree[fav]-- ;
            if(indegree[fav] == 0){
                q.push(fav) ;
            }
        }

        int cycleLength = 0 , chainLen = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(vis[i])continue ;
            int node = i , ct = 0 ;
            while(!vis[node]){
                vis[node] = 1 ;
                ct++ ;
                node = favorite[node] ;
            }
            if(ct == 2){
                chainLen += 2 + chainLength[node] + chainLength[favorite[node]] ; 
            }else{
                cycleLength = max(cycleLength , ct) ;
            }
        }
        return max(cycleLength , chainLen) ;
    }
};