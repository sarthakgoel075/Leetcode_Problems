class Solution {
public:
    int fun(vector<int>&nums,int left,int right){
        if(left>right)return INT_MAX;
        int mid=left+(right-left)/2;
        if(nums[mid]>=nums[left]){
          int x=fun(nums,mid+1,right);
          return min(nums[mid],min(nums[left],x));
        }
        else{
           int x=fun(nums,left,mid-1);
           return min(nums[mid],min(nums[mid+1],x));
        }
    }
    int findMin(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
};