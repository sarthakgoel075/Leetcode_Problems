class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
adj[i].push_back({j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
adj[j].push_back({i, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
               }
            }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         int ans=0;
         pq.push({0,0});
         vector<int>visited(n,0);
         while(!pq.empty()){
            int w=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(visited[u])continue;
            ans+=w;
            visited[u]=1;
            for(auto it:adj[u]){
                if(!visited[it.first]){
                    pq.push({it.second,it.first});
                }
            }
         }
         return ans;
        }
    
};