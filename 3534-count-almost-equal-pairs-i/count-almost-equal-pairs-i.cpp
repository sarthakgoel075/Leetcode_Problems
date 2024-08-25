class Solution {
public:
    int fun(vector<int>&nums,int a,int b){
    if(nums[a]==nums[b])return 1;
    string c=to_string(nums[a]);
    for(int i=0;i<c.size();i++){
        for(int j=i+1;j<c.size();j++){
            string d=c;
            swap(d[i],d[j]);
            if(stoi(d)==nums[b]){
                return 1;
            }
        }
    }
    return 0;
    }
    int countPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                 if(fun(nums,i,j) || fun(nums,j,i)){
                    count++;
                 }
            }
        }
        return count;
    }
};