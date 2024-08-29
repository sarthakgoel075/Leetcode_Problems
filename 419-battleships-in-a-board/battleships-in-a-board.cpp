class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&visited , vector<vector<char>>&board){
        visited[i][j]=1;
        vector<int>row={-1,0,1,0};
        vector<int>col={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=i+row[k];
            int nc=j+col[k];
            if(nr>=0 && nc>=0 && nr<board.size() && nc< board[0].size() && board[nr][nc]=='X' && !visited[nr][nc]){
            dfs(nr,nc,visited,board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X' && !visited[i][j]){
                    count++;
                    dfs(i,j,visited,board);
                }
            }
        }
        return count;
    }
};