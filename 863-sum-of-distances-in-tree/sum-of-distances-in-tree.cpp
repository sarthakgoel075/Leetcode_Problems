class Solution {
public:
    long long ans = 0;

    int dfs(int i, vector<vector<int>>& adj, int level, vector<int>& child, int pre) {
        ans += level;
        int node = 1;
        for (auto it : adj[i]) {
            if (it == pre) continue;
            node += dfs(it, adj, level + 1, child, i);
        }
        child[i] = node;
        return node;
    }

    void dfsfull(vector<vector<int>>& adj, int node, int parent, vector<int>& result, vector<int>& child, int n) {
        for (auto i : adj[node]) {
            if (i == parent) continue;
            result[i] = result[node] - child[i] + (n - child[i]);
            dfsfull(adj, i, node, result, child, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> child(n, 0);
        vector<int> result(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, adj, 0, child, -1);
        result[0] = ans;
        dfsfull(adj, 0, -1, result, child, n);
        return result;
    }
};
