class Solution {
public:
    int fun(int i,vector<int>&nums,vector<int>&dp){
       int n=nums.size();
       if(i>=n)return 0;
              if(dp[i]!=-1)return dp[i];

       int take=0;
       int nottake=0;
       //take case
        
         take=nums[i]+fun(i+2,nums,dp);
           
        // not take case
        nottake=fun(i+1,nums,dp);
        return dp[i]=max(take,nottake);
       }
    
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
       return fun(0,nums,dp);
    }
};