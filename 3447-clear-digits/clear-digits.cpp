class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto i:s){
           if(i-'0'>=0  && i-'0'<=9){
            if(!st.empty()){
                st.pop();
            }
           }
           else{
            st.push(i);
           }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};