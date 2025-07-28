class Solution {
public:
    long long fun(vector<int>&nums,int i,int a,vector<vector<long long>>&dp){
        if(i>=nums.size())return 0;
        if(dp[i][a]!=-1)return dp[i][a];
        long long take=0;
        long long nottake=0;
        if(a==1){
           take=nums[i]+fun(nums,i+1,0,dp);
       }
        else if(a==0){
        take=-nums[i]+fun(nums,i+1,1,dp);
       }
       nottake=fun(nums,i+1,a,dp);
       return dp[i][a]= max(take,nottake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
       vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
       return fun(nums,0,1,dp);        
    }
};