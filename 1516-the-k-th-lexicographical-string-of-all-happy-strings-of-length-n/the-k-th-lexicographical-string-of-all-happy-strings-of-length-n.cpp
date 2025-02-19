class Solution {
public:
    string ans="";
    vector<char>v={'a','b','c'};
    void fun(int &i,string &curr,int k,int n,char ch){
        if(curr.size()==n){
              i++;
              if(i==k){
                ans=curr;
              }
              return;
        }
        for(int j=0;j<3;j++){
          if(ch!=v[j]){
            curr+=v[j];
            fun(i,curr,k,n,v[j]);
            curr.pop_back();
          }
        }
        return;
    }
    string getHappyString(int n, int k) {
        string curr="";
        int i=0;
        fun(i,curr,k,n,'\0');
        return ans;
    }
};