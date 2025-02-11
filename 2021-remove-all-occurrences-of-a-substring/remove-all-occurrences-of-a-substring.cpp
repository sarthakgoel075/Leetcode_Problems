class Solution {
public:
    string removeOccurrences(string s, string part) {
        int size=part.size();
        stack<char>st;
        for(auto i:s){
            st.push(i);
            if(st.size()>=size){
                string temp="";
                for(int i=0;i<size;i++){
                    temp=st.top()+temp;
                    st.pop();
                }
                if(temp!=part){
                    for(auto t:temp){
                        st.push(t);
                    }
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};