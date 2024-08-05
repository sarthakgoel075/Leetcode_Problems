class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }
queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {src, 0}});
        vector<int> v(n, INT_MAX);  // Correct size
        v[src] = 0;
        while (!pq.empty()) {
            int stops = pq.front().first;
            int city = pq.front().second.first;
            int dist = pq.front().second.second;
            pq.pop();
            if (stops > k) continue;
            for (auto it : adj[city]) {
                int ndist = it.second + dist;
                int ncity = it.first;
               
                    if (v[ncity] > ndist && stops<=k+1) {
                        v[ncity] = ndist;
                        pq.push({stops+1, {ncity, ndist}});
                    }
                
            }
        }
        return v[dst] != INT_MAX ? v[dst] : -1;
    }
};
