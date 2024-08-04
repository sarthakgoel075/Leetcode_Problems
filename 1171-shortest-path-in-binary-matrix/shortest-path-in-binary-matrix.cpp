class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        // Edge case for a single cell grid
        if (n == 1) {
            return 1;
        }
        q.push({1,{0,0}});
        grid[0][0] = 1; 
        while(!q.empty()){
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx=x+i;
                    int ny=y+j;
                    if(nx>=0 && ny>=0 && nx<n && ny<n ){
                        if(nx==n-1 && ny==n-1){
                            return dist+1;
                        }
                        if(grid[nx][ny]==0){
                        q.push({dist+1,{nx,ny}});
                          grid[nx][ny] = 1;
                          }
                    }
                }
            }
        }
      return -1;
    }
};