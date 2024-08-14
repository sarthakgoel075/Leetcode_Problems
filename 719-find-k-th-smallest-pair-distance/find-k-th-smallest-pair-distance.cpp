class Solution {
public:
    int solve(int mid,vector<int>&nums){
        int count=0;
        int j=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
              while(nums[i]-nums[j]>mid){
                j++;
              }
              count+=i-j;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int high=nums[n-1]-nums[0];
        int low=INT_MAX;
        for(int i=0;i<n-1;i++){
             low=min(low,nums[i+1]-nums[i]);
        }
        while(low<high){
            int mid=low+((high-low)/2);
            int c=solve(mid,nums);
            if(c<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};