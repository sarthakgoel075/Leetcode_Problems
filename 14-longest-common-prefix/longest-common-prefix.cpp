class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string a=s[0];
        int m=INT_MAX;
        for(int i=1;i<s.size();i++)
        {
            int k=min(a.size(),s[i].size());
            int c=k;
            for(int j=0;j<k;j++)
            {
                if(a[j]!=s[i][j]){
                    c=j;
                    break;
                }
            }
            m=min(m,c);
        }
        return s[0].substr(0,m);
    }
};