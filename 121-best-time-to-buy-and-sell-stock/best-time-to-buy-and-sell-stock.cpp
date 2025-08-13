class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=1e9;
        int ans=INT_MIN;
        for(auto i:prices){
            ans=max(ans,i-mini);
            mini=min(mini,i);
        }
        return (ans>0)?ans:0;
    }
};