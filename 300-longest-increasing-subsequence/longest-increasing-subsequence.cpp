class Solution {
public:
    int fun(int ind,int preind,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==nums.size())return 0;
        if(dp[ind][preind+1]!=-1)return dp[ind][preind+1];
        int take=INT_MIN;
        int nottake=INT_MIN;
        if(preind==-1 || nums[preind]<nums[ind]){
            take=1+fun(ind+1,ind,nums,dp);
        }
        nottake=fun(ind+1,preind,nums,dp);
        return dp[ind][preind+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fun(0,-1,nums,dp);
    }
};