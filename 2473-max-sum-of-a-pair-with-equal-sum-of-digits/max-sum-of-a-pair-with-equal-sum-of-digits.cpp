class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int maxi=INT_MIN;
        for(auto i:nums){
            int num=i;
            int sum=0;
            while(num){
                sum=sum+num%10;
                num=num/10;
            }
            if(mp.count(sum)>=1){
                for(auto t:mp[sum]){
                   maxi=max(maxi,i+t);
                }
            }
          mp[sum].push_back(i);
        }
        return maxi>0?maxi:-1;
    }
};