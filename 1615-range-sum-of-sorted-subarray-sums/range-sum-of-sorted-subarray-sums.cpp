class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subsum;
        int mod=1000000007;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                subsum.push_back(sum);
            }
        }
        sort(subsum.begin(),subsum.end());
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans+=subsum[i];
            ans=ans%mod;
            
        }
        return ans;
    }
};