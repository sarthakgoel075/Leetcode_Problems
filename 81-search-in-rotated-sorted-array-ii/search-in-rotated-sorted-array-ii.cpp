class Solution {
public:
    int fun(vector<int>&nums,int left,int right,int target){
        if(left>right)return false;
        int mid=left + (right-left)/2;
        if(nums[mid]==target)return true;
         if (nums[left] == nums[mid] && nums[mid] == nums[right])
            return fun(nums, left + 1, right - 1, target);
        if(nums[left]<=nums[mid]){
          if(nums[left]<=target && nums[mid]>target){
            return fun(nums,left,mid-1,target);
          }
          else return fun(nums,mid+1,right,target);
        }
        else{
            if(nums[mid]<target && nums[right]>=target){
               return  fun(nums,mid+1,right,target);
            }
            else{
               return fun(nums,left,mid-1,target);
            }

        }
        return true;
    }
    bool search(vector<int>& nums, int target) {
       return fun(nums,0,nums.size()-1,target);
    }
};