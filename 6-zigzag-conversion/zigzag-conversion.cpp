class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>v(numRows);
        int i=0;
        while(i<s.length()){
            for(int j=0;j<numRows && i<s.length();j++){
             v[j]+=s[i++];
            }
            for(int j=numRows-2; j>0 && i<s.length();j--){
                v[j]+=s[i++];
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=v[i];
        }
        return ans;
    }
};