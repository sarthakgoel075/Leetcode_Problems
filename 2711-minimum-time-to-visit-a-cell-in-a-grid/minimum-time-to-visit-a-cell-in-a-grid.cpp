class Solution {
public:
     vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> weight(n, vector<int>(m, INT_MAX));
        if(grid[1][0]>1 && grid[0][1]>1)return -1;
        weight[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int w = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (w > weight[i][j]) continue;

            for (auto dir : direction) {
                int n_i = i + dir[0];
                int n_j = j + dir[1];

                if (n_i >= 0 && n_j >= 0 && n_i < n && n_j < m) {
                    int diff=grid[n_i][n_j]-(w+1);
                    int n_w=0;
                    if(diff<=0)n_w=w+1;
                    else if(diff>0){
                        if(diff%2==0){
                            n_w=grid[n_i][n_j];
                        }
                        else{
                             n_w=grid[n_i][n_j]+1;
                        }
                    }
                    if (n_w < weight[n_i][n_j]) {
                        weight[n_i][n_j] = n_w;
                        pq.push({n_w, {n_i, n_j}});
                    }
                }
            }
        } 
        if(weight[n-1][m-1]==INT_MAX)return -1;
        return weight[n-1][m-1];
    }
    
};