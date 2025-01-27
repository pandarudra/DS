//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    vector<int> khan(vector<vector<int>>& graph){
        int n = graph.size() ;
        vector<int> res , indegree(n , 0) ;
        queue<int> q ;
        
        for(int i = 0 ; i < n ; i++){
            for(auto &it : graph[i]){
                indegree[it]++ ;
            }
        }
        
        for(int  i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            res.push_back(node) ;
            for(auto &it : graph[node]){
                indegree[it]-- ;
                if(indegree[it] == 0){
                    q.push(it) ;
                }
            }
        }
        return res ;
    }
  public:
    string findOrder(vector<string> dict, int k) {
        vector<vector<int>> graph(k) ;
        
        int n = dict.size() ;
        
        for(int i = 0 ; i < n - 1 ; i++){
           string s1 = dict[i] ;
           string s2 = dict[i + 1] ;
           int length = min(s1.length() , s2.length()) ;
           for(int i = 0 ; i < length ; i++){
               if(s1[i] != s2[i]){
                   graph[s1[i] - 'a'].push_back(s2[i] - 'a') ;
                   break ;
               }
           }
        }
        
        vector<int> kh = khan(graph) ;
        string res = "" ;
        for(auto &it : kh){
            res += char(it + 'a') ;
        }
        return res ;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends