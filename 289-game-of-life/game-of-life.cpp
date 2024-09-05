class Solution {
public:
    int fun(vector<vector<int>>& board,int i,int j){
        int count=0;
        vector<int>row={-1,-1,-1,0,0,1,1,1};
        vector<int>col={-1,0,1,-1,1,-1,0,1};
        for(int k=0;k<8;k++){
          int nrow=i+row[k];
          int ncol=j+col[k];
          if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size()){
            if(board[nrow][ncol]/2==1){
                count++;
            }
          }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  board[i][j]= board[i][j]*2+ board[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=fun(board,i,j);
                if(board[i][j]/2==0 && (count==3)){
                    board[i][j]++;
                }
                else if(board[i][j]/2==1 && (count>3||count<2)){
                    board[i][j]--;
                }
            }
        }
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  board[i][j]= board[i][j]%2;
            }
        }
    }
};