class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax=0;
        int maxi=INT_MIN;
        for(auto i:nums){
          currmax+=i;
          maxi=max(maxi,currmax);
          if(currmax<0)currmax=0;
        }
        int currmin=0;
        int mini=INT_MAX;
        for(auto i:nums){
            currmin+=i;
            mini=min(mini,currmin);
            if(currmin>0)currmin=0;
        }
        return max(abs(mini),maxi);
    }
};