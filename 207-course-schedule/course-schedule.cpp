class Solution {
public:
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathvisit){
      
        for(auto it:adj[i]){
            if(!visited[it]){
                visited[it]=1;
                pathvisit[it]=1;
               if(!dfs(it,adj,visited,pathvisit))return false;
                pathvisit[it]=0;

            }
            else if(visited[it] && pathvisit[it]){
                return false;
                }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(numCourses,0);
        vector<int>pathvisit(numCourses,0);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (!dfs(i, adj, visited, pathvisit)) return false;
            }
        }
        return true;
    }
};