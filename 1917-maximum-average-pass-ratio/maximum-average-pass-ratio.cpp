class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto i:classes){
            double ratio=double(i[0]+1)/(double)(i[1]+1)-(double(i[0])/(double)i[1]);
            pq.push({ratio,{i[0],i[1]}});
        }
        while(extraStudents){
            double ratio=pq.top().first;
            int pass=pq.top().second.first+1;
            int total=pq.top().second.second+1;
            double curr = double(pass+1)/(total+1) - double(pass)/total;
            pq.pop();
            pq.push({curr,{pass,total}});
            extraStudents--;
        }
              double ans = 0;
        while(!pq.empty()) {
            ans += double(pq.top().second.first) / pq.top().second.second;
            pq.pop();
        }
        return ans / classes.size();

    }
};