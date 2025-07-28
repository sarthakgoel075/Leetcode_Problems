class Solution {
public:
    bool check(int j,int i,vector<string>&words){
        int count=0;
        if(words[j].size()-words[i].size()!=1)return false;
        int ind1=0;
        int ind2=0;
        int siz=words[j].size();
        while(ind2<siz){
            if(words[i][ind1]!=words[j][ind2]){
                count++;
                ind2++;
                if(count>1)return false;
            }
           else{
            ind1++;
            ind2++;
           }
        }
        return count==1;
    }
    int fun(int ind,int preind,vector<string>&words,vector<vector<int>>&dp){
        if(ind>=words.size())return 0;
        if(dp[ind][preind+1]!=-1)return dp[ind][preind+1];
        int take=0;
        int nottake=0;
        if(preind==-1 || check(ind,preind,words)){
            take=1+fun(ind+1,ind,words,dp);
        }
        nottake=fun(ind+1,preind,words,dp);
        return dp[ind][preind+1]= max(take,nottake);
    }
    int longestStrChain(vector<string>& words) {
        vector<vector<int>>dp(words.size(),vector<int>(words.size()+1,-1));
       sort(words.begin(),words.end(),[](const auto a,const auto b){
        return a.size()<b.size();
       });
       return fun(0,-1,words,dp);
    }
};