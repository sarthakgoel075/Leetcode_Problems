class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currmax=0;
        int ans=0;
        int pre=INT_MIN;
        for(int i=0;i<nums.size();i++){
          if(nums[i]>pre){
            currmax+=nums[i];
            pre=nums[i];
          }
          else{
            ans=max(ans,currmax);
            currmax=nums[i];
            pre=nums[i];
          }
        }
         ans=max(ans,currmax);

        return ans;
    }
};