class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr=i-nums[i];
            int same=0;
            if(mp.count(curr)){
                same=mp[curr];
            }
            ans+=(i-same);
            mp[curr]++;
        }
        return ans;
    }
};