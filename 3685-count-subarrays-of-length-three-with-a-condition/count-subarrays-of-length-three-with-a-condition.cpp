class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if (nums.size() <= 2)
            return 0;
        int left = 0;
        int right = 2;
        int count = 0;
        int n=nums.size();
        while (right < n) {
            if(2*(nums[left]+nums[right])==nums[left+1])count++;
            left++;
            right++;
        }
        return count;
    }
};