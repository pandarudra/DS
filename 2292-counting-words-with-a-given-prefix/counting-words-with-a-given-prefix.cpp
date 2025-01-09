class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len=pref.length();
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            string prefix=words[i].substr(0,len);
            if(pref==prefix){
                cnt++;
            }
        }
        return cnt;
    }
};