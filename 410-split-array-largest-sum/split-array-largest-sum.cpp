class Solution {
public:
    int check(int mid,vector<int>& nums){
        int count=0;
        int curr=0;
        for(auto i:nums){
            if(curr+i>mid){
                count++;
                curr=i;
            }
            else{
                curr+=i;
            }
        }
        count++;
        cout<<count;
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        for(auto i:nums){
            low=max(low,i);
            high+=i;
        }

        int temp = low;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int count=check(mid,nums);
            if(count==k){
                ans=min(ans,mid);
                high=mid-1;
            }
            else if(count>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans == INT_MAX ? low : ans ;
    }
};