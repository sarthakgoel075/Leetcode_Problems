class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
          if(i=='(' || i=='{' || i=='['){
            st.push(i);
          }
          else{
            if(i==')'){
               if(st.size()!=0 && st.top()=='('){
                  st.pop();
               }
               else {
                return false;
               }
            }
            else if(st.size()!=0 && i=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                  if(st.size()!=0 && st.top()=='['){
                    st.pop();
                  }
                  else {
                    return false;
                  }
            }
          }
        }
        return st.size()==0;
    }
};