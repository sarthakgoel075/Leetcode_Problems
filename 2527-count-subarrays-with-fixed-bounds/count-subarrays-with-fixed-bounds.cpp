class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
         long long  minindex=-1;
         long long  maxindex=-1;
         long long  culindex=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK)
                culindex=i;

            if(nums[i]==minK)minindex=i;

            if(nums[i]==maxK)maxindex=i;

           long long smaller=min(minindex,maxindex);
           long long temp=smaller-culindex;
           if(temp>0)ans+=temp;    
        }
        return ans;
    }
};