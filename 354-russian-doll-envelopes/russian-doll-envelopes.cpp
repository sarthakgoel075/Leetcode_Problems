class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
    
          sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
       vector<int>dp;
       for(auto i:envelopes){
        int h=i[1];
        auto it=lower_bound(dp.begin(),dp.end(),h);
        if(it==dp.end()){
            dp.push_back(h);
        }
        else{
            *it=h;
        }
       }
       return dp.size();
    }
};