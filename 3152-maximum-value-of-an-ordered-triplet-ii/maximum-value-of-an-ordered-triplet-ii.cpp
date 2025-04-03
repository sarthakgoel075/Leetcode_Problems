class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int maxi=nums[0];
        vector<int>pre(n,-1);
        vector<int>suc(n);
        for(int i=1;i<n;i++){
            pre[i]=maxi;
            maxi=max(maxi,nums[i]);
        }
        maxi=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suc[i]=maxi;
             maxi=max(maxi,nums[i]);
        }

        for(int i=1;i<n-1;i++){
         ans=max(ans,(long long)(pre[i]-nums[i])*suc[i]);
        }
        return ans;
    }
};