class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        int l=0;
        int r=nums.size()-1;
        if(nums[r]!=nums[r-1])return nums[r];
        while(l<=r){
            int mid=l+ (r-l)/2;
            if(nums[mid-1]!=nums[mid]   && nums[mid+1]!=nums[mid]){
                return nums[mid];
            }
            if(((nums[mid-1]==nums[mid]) && ((mid)%2==1))  || ((nums[mid+1]==nums[mid])&&(mid%2==0))){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};