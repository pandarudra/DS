//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define uset unordered_set
class Solution {
  public:
    void bfs(vector<vector<int>>& grid , int i , int j , vector<vector<int>>& vis,set<vector<pair<int,int>>>& shapes){
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue<pair<int,int>> q ;
        q.push({i,j}) ;
        
        int baserow = i ;
        int basecol = j ;
        
        vector<pair<int,int>> shape ;
        shape.push_back({0,0}) ;
        int drow[4] = {-1,0,1,0} ;
        int dcol[4] = {0,1,0,-1} ;
        vis[i][j] = 1 ;
        while(!q.empty()){
            int u = q.front().first ;
            int v = q.front().second ;
            q.pop() ;
            
            for(int k = 0 ; k < 4 ; k++){
                int row = u + drow[k] ;
                int col = v + dcol[k] ;
                if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1 && !vis[row][col]){
                    q.push({row,col}) ;
                    vis[row][col] = 1 ;
                    shape.push_back({row - baserow , col - basecol}) ;
                }
            }
            
        }
        shapes.insert(shape) ;
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        set<vector<pair<int,int>>> shapes ;
        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    bfs(grid,i,j,vis,shapes) ;
                }
            }
        }
        return shapes.size() ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends