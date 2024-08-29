class Solution {
public:
   
    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        visited[i][j]=1;
       int count=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<int>row={-1,0,1,0};
        vector<int>col={0,-1,0,1};
        while(!q.empty()){
         int r=q.front().first;
         int c=q.front().second;
         count++;
         q.pop();
         for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] && !visited[nr][nc]){
                visited[nr][nc]=1;
               q.push({nr,nc});
            }
         }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]){
                ans= max(ans,fun(i,j,grid,visited));
                }
            }
        }
        return ans;
    }
};