class Solution {
public:
    int fun(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
        vector<vector<int>>& visited, int i, int j,int flag) {
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, -1, 0, 1};
        if(grid1[i][j]!=1)flag=0;
        visited[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int nr = i + row[k];
                int nc = j + col[k];
                if (nr >= 0 && nc >= 0 && nr < grid2.size() &&
                    nc < grid2[0].size() && grid2[nr][nc] == 1 &&
                    visited[nr][nc] == -1) {
                   int next=fun(grid1,grid2,visited,nr,nc,flag);
                   if(next==0)flag=0;
                }
            }
            return flag;
        }
      
    
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && visited[i][j] == -1) {
                  
                   count+= fun(grid1, grid2, visited, i, j,1);
                }
            }
        }
        return count;
    }
};