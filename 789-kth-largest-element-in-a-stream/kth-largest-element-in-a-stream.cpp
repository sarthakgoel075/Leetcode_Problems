class KthLargest {
public:
   
    int f;
    priority_queue<int , vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
         f=k;
        for(auto it: nums)
        {
            pq.push(it);
        }
        while(pq.size()>f ){
            pq.pop();
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>f){
        pq.pop();}
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */