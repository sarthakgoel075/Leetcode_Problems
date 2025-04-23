class Solution {
public:
    int n=0;
    int m=0;
    int fun(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
          if(j1<0 || j2<0 || j1>=m || j2>=m)return -1e9;
        if(i==n-1){
             if(j1==j2){
            return grid[i][j1];
        }
        else{
            return  grid[i][j2]+grid[i][j1];
           
        }
        };
        int val=0;
        if(j1==j2){
            val=grid[i][j1];
        }
        else{
            val+=grid[i][j1];
            val+=grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
       int maxi=INT_MIN;
       for(int k=-1;k<=1;k++){
        for(int t=-1;t<=1;t++){
            maxi=max(maxi,fun(i+1,j1+k,j2+t,grid,dp));
        }
       }
       return dp[i][j1][j2]= val+maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return fun(0,0,m-1,grid,dp);
    }
};