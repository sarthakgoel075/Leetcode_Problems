class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        if(n<=1)return ;
        for(int i=n-2;i>=0 ;i--){
           if(nums[i]<nums[i+1]){
            ind=i;
            break;
           }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int r=n-1;
        while(nums[r]<=nums[ind])r--;

        swap(nums[r],nums[ind]);
        sort(nums.begin()+ind+1,nums.end());
    }
};