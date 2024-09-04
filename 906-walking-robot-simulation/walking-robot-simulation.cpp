#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int currx = 0;
        int curry = 0;
        int dir = 0;  // 0: North, 1: East, 2: South, 3: West
        int maxDistance = 0;

        set<pair<int, int>> obstacleSet;
        for (auto &obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i : commands) {
            if (i == -1) {
                dir = (dir + 1) % 4;  // Turn right
            } else if (i == -2) {
                dir = (dir + 3) % 4;  // Turn left
            } else {
                for (int j = 0; j < i; ++j) {
                    int nx = currx + directions[dir][0];
                    int ny = curry + directions[dir][1];
                    if (obstacleSet.find({nx, ny}) == obstacleSet.end()) {
                        currx = nx;
                        curry = ny;
                        maxDistance = max(maxDistance, currx * currx + curry * curry);
                    } else {
                        break;
                    }
                }
            }
        }
        return maxDistance;
    }
};
