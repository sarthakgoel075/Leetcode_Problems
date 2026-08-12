class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int maxi=0;
        unordered_map<int,int>mp;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
      return maxi;
    }
};