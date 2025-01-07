class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(auto it:words){
            for(auto match:words){
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