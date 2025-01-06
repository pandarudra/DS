class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int> res(n,0);
        
        //left
        res[0]=0;
        int ls=0;
        if(boxes[0]=='1')ls=1;
        for(int i=1;i<n;i++){
            res[i]=res[i-1]+ls;
            if(boxes[i]=='1'){
                ls++;
            }
        }
        //right
        int right=0;
        int rs=0;
        if(boxes[n-1]=='1')rs=1;
        for(int i=n-2;i>=0;i--){
            right+=rs;
            res[i]=res[i]+right;
            if(boxes[i]=='1'){
                rs++;
            }
        }
       
        return res;
    }
};