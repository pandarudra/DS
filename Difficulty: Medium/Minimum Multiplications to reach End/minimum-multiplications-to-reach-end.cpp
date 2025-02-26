//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
#define  ll long long 
#define pll pair<ll , ll>

class Solution {
  private:
    ll dist[100001] ;
    const ll mod = 100000 ;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        ll n = arr.size() ;
        fill(dist, dist + 100001, 1e12);
        
        if(start == end)return 0 ;
        
        priority_queue<pll , vector<pll> , greater<pll>> pq ;
        dist[start] = 0 ;
        pq.push({0 , start}) ;
        // wt --- node
        while(!pq.empty()){
            ll wt = pq.top().first ;
            ll u = pq.top().second ;
            pq.pop() ;
            
            for(auto &it : arr){
                ll v = (it * u) % mod ;
                
                if(wt + 1 < dist[v]){
                    dist[v] = wt + 1 ;
                    pq.push({wt + 1 , v}) ;
                }
            }
        }
        return  (dist[end] == 1e12) ? -1 : dist[end] ;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends