class Solution {
public:
    void fun(vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,vector<int>&cantake){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(cantake[i]){
            curr.push_back(nums[i]);
            cantake[i]=0;
            fun(nums,ans,curr,cantake);
            cantake[i]=1;
            curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        vector<int>cantake(n,1);
        fun(nums,ans,curr,cantake);
        return ans;
    }
};