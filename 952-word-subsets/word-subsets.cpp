class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;

        // Precompute [ frequency ]
        vector<int>  freq(26 , 0);
        for(auto &str : words2){
            unordered_map<char,int> temp;
            for(auto &ch : str){
                temp[ch]++;
            }
            for(auto &it : temp){
                freq[it.first - 'a'] = max(freq[it.first - 'a'] , it.second);
            }
        }

        for(auto &str : words1){
            bool flag = true;
            
            unordered_map<char , int> w1;
            for(auto &ch : str){
                w1[ch]++;
            }

            for(int i = 0 ; i < 26 ; i++){
                if(freq[i] > w1[ i + 'a' ]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                res.push_back(str);
            }
        }
        return res;
    }
};