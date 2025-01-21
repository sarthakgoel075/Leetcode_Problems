class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid[0].size();
         long long firstrow=0;
         long long secrow=0;
        for(int i=0;i<m;i++){
        firstrow+=grid[0][i];
        secrow+=grid[1][i];
        }
         long long ans=LLONG_MAX;
         long long currfirst=0;
         long long currsec=0;
        for(int i=0;i<m;i++){
          currfirst+=grid[0][i];
          if(i>0){
            currsec+=grid[1][i-1];
          }
        ans=min(ans,max(firstrow-currfirst,currsec));

        }
        return ans;
    }
};