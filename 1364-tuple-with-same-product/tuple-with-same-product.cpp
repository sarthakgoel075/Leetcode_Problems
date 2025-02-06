class Solution {
public:
   
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
            mp[nums[i]*nums[j]]++;
           }
        }
        int ans;
        for(auto i:mp){
            int t=i.second;
            ans=ans+((t*(t-1))/2)*8;
        }
        return ans;
    }
};