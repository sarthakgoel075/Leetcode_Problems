class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        for(auto i:nums){
            ones+=i;
        }
        if(ones==0 ||ones==n)return 0;
        nums.insert(nums.end(),nums.begin(),nums.end());
        int i=0;
        int j=0;
        int currone=0;
        int ans=INT_MAX;
        while(j<2*n){
         currone+=nums[j];
         if(j-i+1==ones){
            ans=min(ans,ones-currone);
            currone-=nums[i];
            i++;
         }
         j++;
        }
        return ans;
    }
};