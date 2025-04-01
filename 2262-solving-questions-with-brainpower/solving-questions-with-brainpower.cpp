class Solution {
public:
   
    long long fun(int i,vector<vector<int>>&question,vector<long long>&dp){
        if(i>=question.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        long long take=0;
        
         take=question[i][0]+fun(i+1+question[i][1],question,dp);
       
        long long nottake=0;
        nottake=fun(i+1,question,dp);
    
        return dp[i]=max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long maxi=0;
        int n=questions.size();
        vector<long long>dp(n,-1);
       return fun(0,questions,dp);
       
    }
};