class Solution {
public:
     int n;
    int m;
    int count=0;
    vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
    void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&grid,int id){
            visited[i][j]=1;
            grid[i][j]=id;
            count++;
            for(int k=0;k<4;k++){
                        int i_=i+dir[k][0];
                        int j_=j+dir[k][1];
                        if(i_>=0 && j_>=0 && i_<n &&  j_<m && grid[i_][j_]!=0 && !visited[i_][j_]){
                            dfs(i_,j_,visited,grid,id);
                        }
            }
            return ;
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(i,j,visited,grid,id);
                    mp[id]=count;
                    ans=max(ans,count);
                    count=0;

                    id++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    unordered_map<int,int>cantake;
                     int curr=1;
                    for(int k=0;k<4;k++){
                        int i_=i+dir[k][0];
                        int j_=j+dir[k][1];
                        if(i_>=0 && j_>=0 && i_<n &&  j_<m && grid[i_][j_]!=0){
                          cantake[grid[i_][j_]]++;
                          if(cantake[grid[i_][j_]]==1){
                          curr+=mp[grid[i_][j_]];
                        }

                        }
                    }
                      ans=max(curr,ans);

                }
            }
        }
        return ans;
    }
};