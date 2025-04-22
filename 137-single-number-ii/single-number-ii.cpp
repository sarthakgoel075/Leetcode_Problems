class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<n;j++){
               int t=1;
               if(nums[j]>>i&t){
                count++;
               }
            }
            if(count%3==1){
             int t=1;
             t=t<<i;
            ans=ans|t;
            }
        }
        return ans;
    }
};