class Solution {
public:
    int findparent(int i,vector<int>&parent){
        int t=parent[i];
        if(i!=t){
            t=findparent(t,parent);
        }
        return t;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    int pv=findparent(i,parent);
                    int pu=findparent(j,parent);
                    if(pv!=pu){
                        if(rank[pv]>rank[pu]){
                            parent[pu]=pv;
                        }
                        else if(rank[pu]>rank[pv]){
                            parent[pv]=pu;
                        }
                        else{
                            parent[pu]=pv;
                            rank[pv]++;
                        }
                    }
                }
            }
        }
        set<int>s;
       for (int i = 0; i < n; i++) {
    s.insert(findparent(i, parent));  // Use findparent to get the actual parent
}
        return n-s.size();
    }
};