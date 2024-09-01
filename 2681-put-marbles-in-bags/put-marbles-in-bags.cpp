class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>pairsum;
        for(int i=0;i<weights.size()-1;i++){
            pairsum.push_back(weights[i]+weights[i+1]);
        }
        sort(pairsum.begin(),pairsum.end());
        long long ans=0;
        int n=pairsum.size();
         for(int i=0;i<k-1;i++){
             ans=ans+(pairsum[n-1-i]-pairsum[i]);
         }
         return ans;
    }
};