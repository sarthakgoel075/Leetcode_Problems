class Solution {
public:
    void solve(vector<vector<int>>&grid,vector<vector<int>>&visited,int r,int c){
        visited[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
       vector<int>row={-1,0,1,0};
       vector<int>col={0,-1,0,1};
       for(int i=0;i<4;i++){
        int nr=r+row[i];
        int nc=c+col[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !visited[nr][nc]){
            solve(grid,visited,nr,nc);
        }
       }
    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visit[i][j]){
                    count++;
                    solve(grid,visit,i,j);
                }
            }
        }
        if(count!=1){
            return 0;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                    solve(grid,visited,i,j);
                }
            }
        }
        if(count!=1)return 1;
        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};