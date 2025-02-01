class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>number;
        int total=1;
        for(int i=1;i<n;i++){
           total=total*i;
           number.push_back(i);
        }
        number.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans+=to_string(number[k/total]);
            number.erase(number.begin()+k/total);
            if(number.size()==0){
                break;
            }
            k=k%total;
            total=total/number.size();
        }
        return ans;
    }
};