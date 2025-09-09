class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0;
        int currdist=startFuel;
        int ans=0;
        priority_queue<int>pq;
        int n=stations.size();
        while(i<n){
            if(currdist>=target)return ans;
            if(stations[i][0]<=currdist){
                pq.push(stations[i][1]);
                 i++;
            }
            else{
                if(pq.size()==0)return -1;
                int maxi=pq.top();
                pq.pop();
                ans++;
                 currdist+=maxi;
            }
           
        }
          while (currdist < target && !pq.empty()) {
            currdist += pq.top();
            pq.pop();
            ans++;
        }
        if(currdist>=target)return ans;
        return -1;
    }
};