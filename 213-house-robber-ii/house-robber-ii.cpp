class Solution {
public:
    int fun(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=0;
        int nottake=0;
        take=nums[i]+fun(i+2,n,nums,dp);
        nottake=fun(i+1,n,nums,dp);
        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,-1);
         vector<int>dp2(n,-1);
         if(nums.size()==1)return nums[0];
         if(nums.size()==2)return max(nums[0],nums[1]);
        int a=fun(0,n-1,nums,dp1);
        int b=fun(1,n,nums,dp2);
        return max(a,b);
    }
};