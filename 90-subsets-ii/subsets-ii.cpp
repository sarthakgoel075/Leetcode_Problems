class Solution {
public:
    void fun(int i,set<vector<int>>&st,vector<int>&nums,vector<int>curr){
        //take
        st.insert(curr);
        if(i==nums.size())return ;
        curr.push_back(nums[i]);
        fun(i+1,st,nums,curr);
        curr.pop_back();
        //not take
        fun(i+1,st,nums,curr);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        fun(0,st,nums,curr);
        vector<vector<int>>ans;
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};