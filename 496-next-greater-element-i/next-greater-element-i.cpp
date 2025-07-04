class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums2.size());
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
                v[i]=-1;
                mp[nums2[i]]=-1;
            }
            else{
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    v[i]=-1;
                    mp[nums2[i]]=-1;
                }
                else{
                    v[i]=st.top();
                    mp[nums2[i]]=st.top();
                }
                st.push(nums2[i]);
            }
        }
        vector<int>ans;
        for(auto i:nums1){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};