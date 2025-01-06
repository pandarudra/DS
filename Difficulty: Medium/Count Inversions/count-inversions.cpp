//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    void merge(vector<int>& arr,int low,int mid,int high,int &cnt){
        int nl=mid-low+1;
        int nr=high-mid;
        vector<int> left(nl),right(nr);
        //left sub array
        for(int i=0;i<nl;i++){
            left[i]=arr[low+i];
        }
        //right sub array
        for(int i=0;i<nr;i++){
            right[i]=arr[mid+1+i];
        }
        int i=0,j=0,k=low;
        while(i<nl && j<nr){
            if(left[i]>right[j]){
                arr[k]=right[j];
                j++;
                cnt+=(nl-i);
            }else{
                arr[k]=left[i];
                i++;
            }
            k++;
        }
         while(i<nl){
            arr[k]=left[i];
            k++;
            i++;
        }
        while(j<nr){
            arr[k]=right[j];
            k++;
            j++;
        }
    }
    void cntInv(vector<int>& arr,int low,int high,int& cnt){
        if(low<high){
            int mid=low+(high-low)/2;
            cntInv(arr,low,mid,cnt);
            cntInv(arr,mid+1,high,cnt);
            merge(arr,low,mid,high,cnt);
        }
    }
    int inversionCount(vector<int> &arr) {
        int cnt=0;
        int n=arr.size();
        cntInv(arr,0,n-1,cnt);
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends