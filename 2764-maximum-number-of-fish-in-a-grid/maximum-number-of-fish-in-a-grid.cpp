class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int n=0;
    int m=0;
    int fun(int r ,int c,vector<vector<int>>&grid,vector<vector<int>>&visited){
     if(r<0 || c<0 || r>=n || c>=m){
        return 0;
     }
     visited[r][c]=1;
     int curr=0;
     if(grid[r][c]!=0){
        curr=grid[r][c];
     }
     for(int i=0;i<4;i++){
        int r_=r+dir[i][0];
        int c_=c+dir[i][1];
        if(r_ >= 0 && c_ >= 0 && r_ < n && c_ < m && !visited[r_][c_] && grid[r_][c_] != 0){
        curr+=fun(r+dir[i][0],c+dir[i][1],grid,visited);
         }
     }
     return curr;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi=0;
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]!=0){
                    int curr=fun(i,j,grid,visited);
                    maxi=max(maxi,curr);
                }
            }
        }
        return maxi;
    }
};