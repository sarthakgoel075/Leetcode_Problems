class Solution {
public:
    int n=0;
    int m=0;
    int fun(int i1,int i2,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp){
                if(i1>n || i2>n || j1>m || j2>m|| grid[i1][j1]==-1 || grid[i2][j2]==-1)return -1e9;
           
        if(i1==n && i2==n && j1==m && j2==m)return grid[i1][j1];
        int curr=0;
        if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];
        if(i1==i2 && j1==j2){
            curr+=grid[i1][j1];
        }
        else{
            curr+=grid[i1][j1];
            curr+=grid[i2][j2];
        }
        int cs1,cs2,cs3,cs4=INT_MIN;
         cs1=fun(i1+1,i2+1,j1,j2,grid,dp); 
          cs2=fun(i1+1,i2,j1,j2+1,grid,dp); 
           cs3=fun(i1,i2+1,j1+1,j2,grid,dp); 
            cs4=fun(i1,i2,j1+1,j2+1,grid,dp);
           return dp[i1][j1][i2][j2]=curr+ max(cs1,max(cs2,max(cs3,cs4))); 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size()-1;
        m=grid[0].size()-1;
        vector<vector<vector<vector<int>>>>dp(n+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(n+1,vector<int>(m+1,-1))));
        int ans= fun(0,0,0,0,grid,dp);
        if(ans>=0)return ans;
        return 0;
    }
};