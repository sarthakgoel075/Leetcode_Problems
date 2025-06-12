class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto i:nums1){
            mp1[i]++;
        }
        for(auto i:nums2){
            mp2[i]++;
        }
        vector<int>ans;
        for(auto i:nums1){
            if(mp1[i]>0 && mp2[i]>0){
                ans.push_back(i);
                mp1[i]--;
                mp2[i]--;
                if(mp1[i]==0)mp1.erase(i);
                if(mp2[i]==0)mp2.erase(i);
            }
        }
        return ans;
    }
};