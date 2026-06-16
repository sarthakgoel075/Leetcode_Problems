class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        vector<pair<int,int>> direction = {
            {-1,0},{1,0},{0,-1},{0,1}
        };

        queue<pair<int,int>> q;

        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==2)
                    q.push({i,j});

                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        int ans = 0;

        while(!q.empty() && fresh > 0){

            int size = q.size();

            for(int ind=0; ind<size; ind++){

                auto [i,j] = q.front();
                q.pop();

                for(auto t:direction){

                    int ni = i + t.first;
                    int nj = j + t.second;

                    if(ni>=0 && ni<n &&
                       nj>=0 && nj<m &&
                       grid[ni][nj]==1){

                        grid[ni][nj] = 2;
                        fresh--;

                        q.push({ni,nj});
                    }
                }
            }

            ans++;
        }

        return fresh==0 ? ans : -1;
    }
};