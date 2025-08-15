class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int curr=1;
        for(auto i:nums){
            curr=curr*i;
            maxi=max(maxi,curr);
            if(curr==0)curr=1;
        }
        curr=1;
        for(int i=nums.size()-1;i>=0;i--){
            curr=curr*nums[i];
            maxi=max(maxi,curr);
            if(curr==0)curr=1;
        }
        return maxi;
    }
};