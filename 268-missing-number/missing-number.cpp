class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
        x=x^i;
        }
        for(auto i:nums){
            x=x^i;
        }
        return x;
    }
};