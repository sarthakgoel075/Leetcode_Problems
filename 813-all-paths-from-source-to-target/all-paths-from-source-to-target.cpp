class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,int n,vector<vector<int>>&ans,vector<int>&curr){
        if(i==n){
            curr.push_back(i);
            ans.push_back(curr);
            return ;
        }
        curr.push_back(i);
        for(auto it:graph[i]){
            dfs(it,graph,n,ans,curr);
                    curr.pop_back();

        }

        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n=graph.size();
        dfs(0,graph,n-1,ans,curr);
        return ans;
    }
};