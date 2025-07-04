class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // vector<int>prefix(nums.size());
        // vector<int>surfix(nums.size());
        int maxi=INT_MIN;
        int n=nums.size();
        int t=1;
        for(int i=0;i<n;i++){
        t=t*nums[i];
       
        maxi=max(t,maxi);
          if(t==0)t=1;
        }
        t=1;
        for(int i=n-1;i>=0;i--){
            t=t*nums[i];
            maxi=max(maxi,t);
             if(t==0)t=1;

        }
        return maxi;
    }
};