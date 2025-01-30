class Solution {
public:
    void fun(int i,vector<int>curr,int sum,  vector<vector<int>>&ans,vector<int>candidates,int target,int cantake){
        if(sum==target && cantake){
            ans.push_back(curr);
        }
        if(sum>target || i>=candidates.size())return ;
        //take
        curr.push_back(candidates[i]);
        fun(i,curr,sum+candidates[i],ans,candidates,target,1);
        curr.pop_back();
        //not take
        fun(i+1,curr,sum,ans,candidates,target,0);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        fun(0,curr,0,ans,candidates,target,1);
        return ans;
    }
};