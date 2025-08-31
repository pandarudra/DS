class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char c){
        for(int  i=0;i<9;i++){
            if(board[i][col]==c)return false;
            if(board[row][i]==c)return false;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c)return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>& res){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(res[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isvalid(res,i,j,ch)){
                            res[i][j]=ch;
                            if(helper(res)){
                                return true;
                            }else{
                                res[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       helper(board);
    }
};