class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            int len=words[i].length();
            for(int j=i+1;j<n;j++){
                int lenj=words[j].length();
                if(len>lenj)continue;
                string_view prefix=string_view(words[j]).substr(0,len);
                string_view suffix=string_view(words[j]).substr(lenj-len,len);
                if(prefix==suffix && prefix==words[i]){
                    cnt++;
                }
            }
        }
        return  cnt;
    }
};