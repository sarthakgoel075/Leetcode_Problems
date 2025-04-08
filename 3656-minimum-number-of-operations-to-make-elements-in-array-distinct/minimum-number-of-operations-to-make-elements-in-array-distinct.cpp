class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       vector<int>v(101,-1);
        int n=nums.size();
        int count=0;
        int point=0;
        for(int i=0;i<nums.size();i++){
           if(point>i)continue;
            if(v[nums[i]]==-1){
                v[nums[i]]=i;
            }
            else if(v[nums[i]]!=-1){
                while(v[nums[i]]>=point){
                point=point+3;
                count=count+1;
                }
                 v[nums[i]]=i;
            }
        }
    return count;
    }
};