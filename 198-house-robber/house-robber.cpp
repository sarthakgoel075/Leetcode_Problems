class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
          int take=0;
          if(i>=2){
            take=nums[i]+dp[i-2];
          }
          else{
            take=nums[i];
          } 

          int nottake=0;
          if(i>0)nottake=dp[i-1];
          dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};