class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int finalsum=INT_MIN;
        int currsum=0;
        for(auto i:nums){
            currsum+=i;
            if(currsum>finalsum)finalsum=currsum;
            if(currsum<0)currsum=0;
        }
        return finalsum;
    }
};