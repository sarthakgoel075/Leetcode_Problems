class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>curr(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    curr[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto d:dir){
                int i_=i+d[0];
                int j_=j+d[1];
                if(i_>=0 && j_>=0 && i_<n && j_<m && curr[i_][j_]==-1){
                    curr[i_][j_]=curr[i][j]+1;
                                    q.push({i_,j_});

                }
            }
            }
        }
        return curr;
    }
};