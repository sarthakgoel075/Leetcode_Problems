class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int op=0;
        for(auto i:nums){
                while(!st.empty() && st.top()>i ){
                       st.pop();
                }
                if(i==0)continue;
                if(st.empty()||st.top()!=i){
                    st.push(i);
                    op++;
                }
            }
        return op;
    }
};