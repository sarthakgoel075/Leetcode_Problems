class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        vector<pair<double, int>> worker(n);
        for (int i = 0; i < n; i++) {
            double ratio = double(wage[i]) / quality[i];
            worker[i] = {ratio, quality[i]};
        }
        sort(worker.begin(), worker.end());
        double result=DBL_MAX;
         int sum=0;
         priority_queue<int>pq;
         for(int i=0;i<k;i++){
          pq.push(worker[i].second);
          sum+=worker[i].second;
         }
         double manager_ratio=worker[k-1].first;
         result=manager_ratio*sum;
         for(int manager=k;manager<n;manager++){
             double manager_ratio=worker[manager].first;
             pq.push(worker[manager].second);
             sum+=worker[manager].second;
             if(pq.size()>k){
               sum-=pq.top();
               pq.pop();
             }
             result=min(result,manager_ratio*sum);
         }
         return result;
    }
};