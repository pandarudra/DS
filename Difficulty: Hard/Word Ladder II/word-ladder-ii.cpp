//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define uset unordered_set
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res ;
         uset<string> st(wordList.begin(),wordList.end()) ;
         
         if(!st.count(endWord))return {} ;

         queue<vector<string>> q ;

         q.push({beginWord}) ;
         int level = 0 ;

         vector<string> used ;
         used.push_back(beginWord) ;

         while(!q.empty()){
            vector<string> v = q.front() ;
            q.pop() ;

            if(v.size() > level){
                level++ ;
                for(auto &it : used){
                    st.erase(it) ;
                }
                used.clear() ;
            }

            string  word = v.back() ;
            if(word == endWord){
                if(res.size() == 0){
                    res.push_back(v) ;
                }else if (res[0].size() == v.size()){
                    res.push_back(v) ;
                }
            }

            for(int i = 0 ; i < word.length() ; i++){
                string original = word ;
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch ;
                    if(st.count(word)){
                        v.push_back(word) ;
                        q.push(v) ;
                        used.push_back(word) ;
                        v.pop_back() ;
                    }
                }
                word = original ;
            }
         }
         return res ;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends