class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int one=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)one=1;
            if(nums[i]<=0 || nums[i]>n)nums[i]=1;
        }
        for(int i=0;i<nums.size();i++){
            int pos=abs(nums[i])-1;
            if(nums[pos]>0){
                nums[pos]=nums[pos]*-1;
            }
        }
        int ans=0;
        if(one==0)return 1;
        for(int i=1;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};