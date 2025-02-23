class Solution {
public:
    // Map a boundary point (x,y) to a 1D coordinate on the perimeter
    long long fun(int side, int x, int y) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return (3LL * side) - x;  // Avoid overflow
        return (4LL * side) - y;                 // Avoid overflow
    }

    // Check if it's possible to place k points with at least `mid` distance
    bool check(long long mid, vector<long long>& t, int k, long long side) {
        int n = t.size();
        for (int i = 0; i < n; i++) {
            long long pnt = t[i];
            int ind = i;
            int count = 1;
            while (count < k && ind < n) {
                auto id = std::lower_bound(t.begin() + ind + 1, t.end(), pnt + mid);
                if (id != t.end()) {
                    ind = id - t.begin();
                    pnt = t[ind];
                    count++;
                } else {
                    break;
                }
            }
            if (count == k) {
                long long gap = (4LL * side + t[i] - t[ind]) % (4LL * side);
                if (gap >= mid) return true;
            }
        }
        return false;
    }

    // Binary search for the maximum distance
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> t(points.size());
        for (int i = 0; i < points.size(); i++) {
            t[i] = fun(side, points[i][0], points[i][1]);
        }
        sort(t.begin(), t.end());
        
        long long left = 1;
        long long ans = 0;
        long long right = 2LL * side;  // Avoid overflow

        while (left <= right) {
            long long mid = left + (right - left) / 2;  // Safe mid calculation
            if (check(mid, t, k, side)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return static_cast<int>(ans);
    }
};
