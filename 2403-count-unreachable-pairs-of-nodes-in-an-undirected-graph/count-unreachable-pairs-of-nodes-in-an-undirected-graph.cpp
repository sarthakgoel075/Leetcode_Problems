class Solution {
public:
    int fun(int i,vector<int>&visited,vector<int>adj[]){
        int count=0;
        queue<int>q;
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
         int ni=q.front();
         count++;
        //  visited[ni]=1;
         q.pop();
         for(auto ind:adj[ni]){
            if(!visited[ind]){
                visited[ind]=1;
                q.push(ind);
            }
         }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<int>adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long curr=n;
        long long totalPairs=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int componentSize = fun(i, visited, adj);  // Find size of connected component
                totalPairs += static_cast<long long>(componentSize) * (curr - componentSize);
                curr -= componentSize;

            }
        }
        return totalPairs;
    }
};