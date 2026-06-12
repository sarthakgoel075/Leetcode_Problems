class Solution {
public:
    vector<int> fun(vector<int>inp){
        if(inp.size()==0)return {};
        vector<int>res;
        res.push_back(inp[0]);
        for(int i=0;i<inp.size()-1;i++){
            res.push_back(inp[i]+inp[i+1]);
        }
        res.push_back(inp[inp.size()-1]);
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<int>v={1};
        vector<vector<int>>result;
        result.push_back(v);
        for(int i=2;i<=numRows;i++){
          vector<int>v2= fun(v);
          result.push_back(v2);
          v=v2;
        }
        return result;
    }
};