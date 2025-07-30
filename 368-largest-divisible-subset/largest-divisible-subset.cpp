class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>preind(n,-1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
               if(nums[i]%nums[j]==0 &&  dp[i]<dp[j]+1){
                preind[i]=j;
                dp[i]=dp[j]+1;
               }
            }
        }
        vector<int>ans;
        int maxind=0;
        for(int i=0;i<n;i++){
            if(dp[i]>dp[maxind]){
                maxind=i;
            }
        }
        while(maxind>=0){
          ans.push_back(nums[maxind]);
          maxind=preind[maxind];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};