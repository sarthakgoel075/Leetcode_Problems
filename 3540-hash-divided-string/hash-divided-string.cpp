class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.length();
        int len=k;
        vector<int>sum;
        int t=0;
        int currsum=0;
        for(int i=0;i<s.size();i++){
            currsum+=(s[i]-'a');
            t++;
            if(t==len){
                sum.push_back(currsum%26);
                currsum=0;
                t=0;
            }
        }
        string ans;
        for(auto i:sum){
            char c='a'+i;
            ans+=c;
        }
        return ans;
    }
};