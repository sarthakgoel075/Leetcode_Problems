class Solution {
public:
     char lreq(unordered_map<char,int>&mp){
         for (int i = 0; i < 26; i++) {
            if (mp['a' + i] > 0) // FIXED: Check actual count, not just existence
                return 'a' + i;
        }
        return 'z' + 1; // Something greater than 'z'
     }
    string robotWithString(string s) {
       unordered_map<char,int>mp;
       for(auto i:s){
        mp[i]++;
       }
       string ans="";
       stack<char>st;
       for(auto ch:s){
        st.push(ch);
        mp[ch]--;
        while(st.size()>0 && st.top()<=lreq(mp) ){
            ans+=st.top();
            st.pop();
        }
       }
       while(st.size()>0){
        ans+=st.top();
        st.pop();
       }
       return ans;
    }
};