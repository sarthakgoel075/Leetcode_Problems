class Solution {
public:
    bool check(int mid,vector<int>&nums,int k){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        for(auto i:nums)
        {
            r=max(r,i);
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,nums,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};