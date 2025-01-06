//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &it:arr){
            mp[it]++;
        }
        int n=arr.size();
        for(const auto& it:mp){
            if(it.second>(n/2)){
                return it.first;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends