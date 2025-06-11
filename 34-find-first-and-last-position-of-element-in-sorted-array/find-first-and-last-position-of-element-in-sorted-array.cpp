class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target)break;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
        }
        if(mid<0 || mid>=nums.size()){
            cout<<mid;
            cout<<"in 1st condition";
            return {-1,-1};}
        if(nums[mid]!=target){
            cout<<"in 2nd conditon";
            return {-1,-1};}
        int low=mid;
        int high=mid;
        while( low>=0 && nums[low]==target){
            low--;
        }
        low++;
        int n=nums.size()-1;
        while(high<=n && nums[high]==target){
            high++;
        }
        high--;
        return {low,high};
    }
};