//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define inf INT_MAX
#define umap unordered_map 
class Solution {
    umap<int , int> memo ;
    int dp(vector<int>& ht , int n){
        if(n == 0) return 0 ;
        if(memo.count(n)) return memo[n] ;
        
        int left = dp(ht , n - 1) + abs(ht[n] - ht[n - 1]) ;
        int right = (n >= 2) ? (dp(ht , n - 2) + abs(ht[n] - ht[n - 2])) : inf ;
        return memo[n] = min(left , right) ;    
    }
  public:
    int minCost(vector<int>& height) {
        int mn = inf ;
        int n = height.size() ;
        return dp(height , n - 1) ;
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends