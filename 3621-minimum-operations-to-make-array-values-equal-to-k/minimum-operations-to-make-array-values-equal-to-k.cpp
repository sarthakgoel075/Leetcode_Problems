class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]==1 && i>k){
                count++;
            }
            else if(i<k){
                return -1;
            }
        }
        return count;
    }
};