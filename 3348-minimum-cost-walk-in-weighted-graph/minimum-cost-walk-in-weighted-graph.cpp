class Solution {
public:
    vector<int>parent;
    vector<int>cost;
int findparent(int x){
    if(parent[x] != x){
        parent[x] = findparent(parent[x]); // Path compression
    }
    return parent[x];
}

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent=vector<int>(n);
        cost=vector<int>(n,-1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int parentu=findparent(u);
            int parentv=findparent(v);
             if(parentu != parentv){
                cost[parentu]=cost[parentu]&cost[parentv];
               parent[parentv] = parentu; 
            }
            cost[parentu]=cost[parentu]&i[2];
    
        }
        vector<int>result;
        for(auto i:query){
            int u=i[0];
            int v=i[1];
            int parentu=findparent(u);
            int parentv=findparent(v);
            if(u==v){
                result.push_back(0);
            }
            else if(parentu!=parentv){
                result.push_back(-1);
            }
            else{
                result.push_back(cost[parentu]);
            }
        }
        return result;
    }
};