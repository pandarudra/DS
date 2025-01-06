class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int> res(n);
        vector<int> left(n,0),right(n,0);
        //left
        left[0]=0;
        int ls=0;
        if(boxes[0]=='1')ls=1;
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+ls;
            if(boxes[i]=='1'){
                ls++;
            }
        }
        //right
        right[n-1]=0;
        int rs=0;
        if(boxes[n-1]=='1')rs=1;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+rs;
            if(boxes[i]=='1'){
                rs++;
            }
        }
        //net
        for(int i=0;i<n;i++){
            res[i]=left[i]+right[i];
        }
        return res;
    }
};