//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int vote=0;
        int candidate=-1;
        for(auto &it:arr){
            if(vote==0){
                candidate=it;
                vote++;
            }else{
                if(it==candidate){
                    vote++;
                }else{
                    vote--;
                }
            }
        }
        int freq=0;
        for(auto &it:arr){
            if(it==candidate){
                freq++;
            }
        }
        if(freq>(n/2)){
            return candidate;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.findDuplicates(a);
        sort(result.begin(), result.end());

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no duplicates are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
