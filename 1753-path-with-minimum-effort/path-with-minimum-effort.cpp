#include <vector>
#include <queue>
#include <cmath>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Define a min-heap priority queue
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> v(n, vector<int>(m, INT_MAX));
        v[0][0] = 0;

        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(!pq.empty()) {
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int ndist = max(dist, abs(heights[x][y] - heights[nx][ny]));
                    if(ndist < v[nx][ny]) {
                        v[nx][ny] = ndist;
                        pq.push({ndist, {nx, ny}});
                    }
                }
            }
        }
        return v[n-1][m-1];
    }
};
