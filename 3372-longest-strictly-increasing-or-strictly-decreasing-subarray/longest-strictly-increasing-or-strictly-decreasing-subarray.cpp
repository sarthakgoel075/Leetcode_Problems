class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int len=1;
        int n=nums.size();
        int curr=nums[0];
        int ans=1;
        for(int i=1;i<n;i++){
          if(curr<nums[i]){
            len++;
            ans=max(ans,len);
          }
          else{
            len=1;
          }
         curr=nums[i];
        }
        curr=nums[0];
        len=1;
           for(int i=1;i<n;i++){
          if(curr>nums[i]){
            len++;
            ans=max(ans,len);
          }
          else{
            len=1;
          }
         curr=nums[i];
        }
        return ans;
    }
};