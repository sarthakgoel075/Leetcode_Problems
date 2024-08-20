class Solution {
public:
    int n;
   
       vector<vector<vector<int>>> dp; 

    int solveforalice(vector<int>&piles,int person,int i,int m){
           if(i>=n)return 0;
           int result=(person==1)? -1:INT_MAX;
           int stone=0;
           if(dp[person][i][m]!=-1){
            return dp[person][i][m];
           }
           for(int x=1;x<=min(2*m,n-i);x++){
            stone+=piles[i+x-1];
            if(person==1){
            result=max(result,stone+solveforalice(piles,0,i+x,max(m,x)));
           }
           else{
            result=min(result,solveforalice(piles,1,i+x,max(m,x)));
           }
           }
           return dp[person][i][m]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
         dp = vector<vector<vector<int>>>(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solveforalice(piles,1,0,1);
    }
};