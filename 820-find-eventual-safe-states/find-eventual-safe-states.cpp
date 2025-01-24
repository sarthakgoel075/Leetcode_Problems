class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ngraph(n);
        vector<int>indegree(n,0);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                ngraph[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto i:ngraph[t]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};