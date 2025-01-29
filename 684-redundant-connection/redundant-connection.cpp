class Solution {
public:
    int findparent(int i,vector<int>&parent){
        if(parent[i]==i){
            return i;
        }
        return findparent(parent[i],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto i:edges){
           int parentu=findparent(i[0],parent);
            int parentv=findparent(i[1],parent);
            if(parentu==parentv){
                return i;
            }
            else{
                parent[parentu]=parentv;
            }
        }
        return {};
    }
};