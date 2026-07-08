class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n=nums.size();
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>n-k+1){
                pq.pop();
            }
        }
        return pq.top();
    }
};