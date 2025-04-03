class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums){
            if(i>0)pq.push(i);
        }
        int curr=1;
       while(!pq.empty()){
         if(pq.top()>curr){
            return curr;
         }
         if(pq.top()==curr){
         curr++;
         }
         pq.pop();
       }
       return curr;
    }
};