class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int left=0,right=0;
            for(int j=i-1;j>=0;j--){
                if(boxes[j]=='1'){
                    left+=abs(i-j);
                }
            }
            for(int j=i+1;j<n;j++){
                if(boxes[j]=='1'){
                    right+=abs(i-j);
                }
            }
            res[i]=left+right;
        }
        return res;
    }
};