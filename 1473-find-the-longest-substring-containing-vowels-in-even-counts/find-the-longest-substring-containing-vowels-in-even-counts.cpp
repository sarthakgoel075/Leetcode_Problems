class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string,int>mp;
        int result=0;
        string currstr="00000";
        mp[currstr]=-1;
        vector<int>state(5,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                state[0]=(state[0]+1)%2;
            }
            else if(s[i]=='e'){
                state[1]=(state[1]+1)%2;
            }
             else if(s[i]=='i'){
                state[2]=(state[2]+1)%2;
            }
             else if(s[i]=='o'){
                state[3]=(state[3]+1)%2;
            }
             else if(s[i]=='u'){
                state[4]=(state[4]+1)%2;
            }
            currstr="";
            for(int j=0;j<5;j++){
                currstr+=to_string(state[j]);
            }
            if(mp.find(currstr)!=mp.end()){
                result=max(i-mp[currstr],result);
            }
            else{
                mp[currstr]=i;
            }
        }
        return result;
    }
};