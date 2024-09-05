class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(auto i:rolls){
            sum+=i;
        }
        int size=rolls.size()+n;
        int remaining=(mean*size)-sum;
        int eachhas=remaining/n;
        if(eachhas<1 || eachhas>6)return {};
          vector<int>v(n,eachhas);
        remaining-=n*eachhas;
        int i=0;
        while(remaining>0){
            if(v[i]==6){
                return {};
            }
          v[i]+=1;
          remaining--;
          i++;
          i=i%n;
        }
        return v;
    }
};