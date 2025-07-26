class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        unordered_map<int,unordered_set<int>>mp;
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                mp[i].insert(node);
                for(auto it:mp[node]){
                    mp[i].insert(it);
                }
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        vector<bool>ans;
        for(auto i:queries){
            if(mp[i[1]].count(i[0]))ans.push_back(true);
            else{
                ans.push_back(false);
            }
        }
      return ans;
    }
};