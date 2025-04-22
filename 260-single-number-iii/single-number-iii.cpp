class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long t=0;
        int n=nums.size();
        for(auto i:nums){
            t=t^i;
        }
        long long rightmost=(t&t-1)^t;
        int b1=0;
        int b2=0;
        for(auto i:nums){
            if(i&rightmost){
                b1=b1^i;
            }
            else{
                b2=b2^i;
            }
        }
        return {b1,b2};
    }
};