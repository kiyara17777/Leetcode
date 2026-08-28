class Solution {
public:
    bool issafe(vector<vector<char>>&board,int row,int col,char ch){
        for(int j=0;j<9;j++){
            if(board[row][j]==ch) return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
        }
        int rowstart =(row/3)*3;
        int colstart=(col/3)*3;

        for(int i=rowstart;i<rowstart+3;i++){
            for(int j=colstart;j<colstart+3;j++){
                if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(issafe(board,i,j,c)){
                            board[i][j]=c;
                            if(solveSudoku(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
};