class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rowsize = maze.size();
        int colsize = maze[0].size();
        
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int level = 0;
        
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto [i, j] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int n_i = i + d[0];
                    int n_j = j + d[1];

                    if (n_i < 0 || n_i >= rowsize || n_j < 0 || n_j >= colsize)
                        continue;

                    if (maze[n_i][n_j] == '.') {
                        if ((n_i == 0 || n_i == rowsize - 1 || n_j == 0 || n_j == colsize - 1) &&
                            !(n_i == entrance[0] && n_j == entrance[1])) {
                            return level + 1;
                        }

                        maze[n_i][n_j] = '+'; 
                        q.push({n_i, n_j});
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};
