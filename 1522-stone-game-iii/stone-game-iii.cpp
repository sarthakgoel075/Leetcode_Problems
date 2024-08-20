class Solution {
public:
    vector<int>dp;
    int fun(vector<int>&s,int ind,vector<int>&dp){
          if(ind>=s.size())return 0;
          int ans=INT_MIN;
          if(dp[ind]!=-1)return dp[ind];
          ans=max(ans,s[ind]-fun(s,ind+1,dp));
          if(ind+1<s.size()){
            ans=max(ans,s[ind]+s[ind+1]-fun(s,ind+2,dp));
          }
          if(ind+2<s.size()){
            ans=max(ans,s[ind]+s[ind+1]+s[ind+2]-fun(s,ind+3,dp));
          }
          return dp[ind]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
           dp=vector<int>(stoneValue.size(),-1);
        int ans=fun(stoneValue,0,dp);
     
        if(ans>0){
            return "Alice";
        }
        else if(ans==0){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};