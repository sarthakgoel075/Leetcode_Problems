class Solution {
public:
    bool check(vector<int>&nums,int mid){
         if(mid-1>=0){
            if(nums[mid-1]>nums[mid])return false;
         }
         if(mid+1 <nums.size()){
            if(nums[mid+1]>nums[mid])return false;
         }
         return true;
    }
    int fun(int l,int r,vector<int>nums){
            if(l>r)return -1;
            int mid=(l+r)/2;
            if(check(nums,mid)){
                return mid;
            }
           if (mid > 0 && nums[mid - 1] > nums[mid]) {
            return fun(l, mid - 1, nums);
        } else {
            return fun(mid + 1, r, nums);
        }
    }
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        return fun(0,r,nums);
    }
};