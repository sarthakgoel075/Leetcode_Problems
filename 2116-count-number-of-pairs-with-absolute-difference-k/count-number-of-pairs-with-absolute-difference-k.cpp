class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i;j<nums.size();j++){
                if(nums[j]-nums[i]==k){
                    count++;
                }
                if(nums[j]-nums[i]>k)break;
            }
        }
        return count;
    }
};