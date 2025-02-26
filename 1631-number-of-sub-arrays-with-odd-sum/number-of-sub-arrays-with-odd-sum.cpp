class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int currsum=0;
        int odd=0;
        int even=1;
        int ans=0;
        for(auto i:arr){
            currsum+=i;
            if(currsum%2==0){
              ans=(ans+odd)%mod;
              even++;
            }
            else{
                ans=(ans+even)%mod;
                odd++;
            }
        }
        return ans;
    }
};