class Solution {
public:
    int fun(int ind,int preind,vector<vector<int>>& pairs,vector<vector<int>>&dp){
        if(ind>=pairs.size())return 0;
       
        if(dp[ind][preind+1]!=-1)return dp[ind][preind+1];
        int take=0;
        int nottake=0;
        if(preind==-1|| pairs[preind][1]<pairs[ind][0]){
            take=1+fun(ind+1,ind,pairs,dp);
        }
        nottake=fun(ind+1,preind,pairs,dp);
        return dp[ind][preind+1]= max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(pairs.size(),vector<int>(pairs.size()+1,-1));
        return fun(0,-1,pairs,dp);
    }
};