class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        for(int t=0;t<n;t++){
         if(nums[t]!=0){
            nums[i++]=nums[t];
         }
        }
        while(i<n){
            nums[i++]=0;
        }
    }
};