class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int n = nums.size();
        vector<int> pre(n, 0);
        vector<int> suff(n, 0);
         pre[0]=nums[0];
         suff[n-1]=nums[n-1];
        for (int i = 1; i < n; i++) {
            if (pre[i - 1] == 0) {
                pre[i] = nums[i];
            } else {
                pre[i] = pre[i - 1] * nums[i];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (suff[i + 1] == 0) {
                suff[i] = nums[i];
            } else {
                suff[i] = suff[i + 1] * nums[i];
            }
        }
      int ans=INT_MIN;
      for(int i=0;i<n;i++){
        ans=max(ans,max(pre[i],suff[i]));
      }
    return ans;
    }
};