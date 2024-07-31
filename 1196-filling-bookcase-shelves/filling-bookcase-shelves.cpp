class Solution {
public:
    int solve(int i,vector<vector<int>>& books, int shelfWidth,vector<int>&dp){
        if(i>=books.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int currwidth=0;
        int maxh=0;
        int ans=INT_MAX;
        for(int j=i;j<books.size();j++){
           currwidth+=books[j][0];
           if(currwidth>shelfWidth){break;}
           maxh=max(maxh,books[j][1]);
           ans=min(ans,maxh+solve(j+1,books,shelfWidth,dp));
        }
        return dp[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size(),-1);
        return solve(0,books,shelfWidth,dp);
    }
};