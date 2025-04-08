class Solution {
public:
    bool fun(int i,int currsum,int total,vector<int>nums,vector<vector<int>>&dp){
        if(currsum==total)return true;
        if(currsum>total || i>=nums.size())return false;
        if(dp[i][currsum]!=-1)return dp[i][currsum];
        return dp[i][currsum]=fun(i+1,currsum+nums[i],total,nums,dp)|| fun(i+1,currsum,total,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto i:nums){
            total+=i;
        }
        if(total%2==1)return false;
       vector<vector<int>>dp(nums.size()+1,vector<int>(total/2,-1));
       return  fun(0,0,total/2,nums,dp);
    }
};