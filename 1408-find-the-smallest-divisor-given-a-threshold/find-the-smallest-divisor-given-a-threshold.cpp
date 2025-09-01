class Solution {
public:
     bool check(int i,vector<int>& nums, int threshold){
        int curr=0;
        for(auto it:nums){
         curr+=ceil((double)it/(double)i);
        }
        return curr<=threshold;
     }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lower=1;
        int high=0;
        for(auto i:nums){
            high=max(high,i);
        }
        int ans=INT_MAX;
        while(lower<=high){
           int mid=(lower+high)/2;
            if(check(mid,nums,threshold)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                lower=mid+1;
            }
        }
        return ans;
    }
};