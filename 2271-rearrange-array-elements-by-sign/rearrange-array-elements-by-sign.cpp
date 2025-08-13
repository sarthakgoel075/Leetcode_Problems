class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>arr(nums.size());
        int posi=0;
        int negi=1;
        for(auto i:nums){
            if(i>=0){
                arr[posi]=i;
                posi+=2;
            }
            else{
                arr[negi]=i;
                negi+=2;
            }
        }
        return arr;
    }
};