class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        int n=words.size();
        sort(words.begin(),words.end(),[](const string& a,const string& b){
            return a.length()<b.length();
        });
        for(int i=0;i<n;i++){
            string it=words[i];
            for(int j=i+1;j<n;j++){
                string match=words[j];
                if(it!=match){
                    auto present=match.find(it);
                    if(present!=string::npos){
                        res.push_back(it);
                        break;
                    }
                }
            }
        }
        return res;
    }
};