class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(pq.size()>1 || pq.top()<k){
            long long first=pq.top();
            pq.pop();
            long long second=pq.top();
            if(first>=k)break;
            pq.pop();
            long long number=(first*2)+second;
            pq.push(number);
            cout<<number;
            ans++;
        }
        return ans;
    }
};