class Solution {
public:
    vector<long long> fun(int start,vector<vector<pair<long long,long long>>>&adj){
        vector<long long>weight(adj.size(),LLONG_MAX);
        weight[start]=0;
       priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
       pq.push({0,start});
       while(!pq.empty()){
        auto i=pq.top();
        long long cost=i.first;
        long long curr=i.second;
        pq.pop();
         if (cost > weight[curr]) continue;
        for(auto nxt:adj[curr]){
            long long new_node=nxt.first;
            long long new_cost=cost+nxt.second;
            if(new_cost<weight[new_node]){
                weight[new_node]=new_cost;
                pq.push({new_cost,new_node});
            }
        }
       }
       return weight;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long long,long long>>>adj(n);
           vector<vector<pair<long long,long long>>>rev_adj(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            rev_adj[i[1]].push_back({i[0], i[2]});
        }
        vector<long long> from_src1 = fun(src1, adj);
        vector<long long> from_src2 = fun(src2, adj);
        vector<long long> from_dest = fun(dest, rev_adj);
        
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (from_src1[i] != LLONG_MAX && from_src2[i] != LLONG_MAX && from_dest[i] != LLONG_MAX) {
                ans = min(ans, from_src1[i] + from_src2[i] + from_dest[i]);
            }
        }
        
        return (ans == LLONG_MAX) ? -1 : ans;
    }
};