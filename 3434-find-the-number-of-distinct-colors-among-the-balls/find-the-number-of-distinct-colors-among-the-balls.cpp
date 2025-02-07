class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>ball;
        int count=0;
        vector<int>ans;
        for(auto i:queries){
            int b=i[0];
            int col=i[1];
            if(ball.count(b)){
                mp[ball[b]]--;
                if(mp[ball[b]]==0){
                    mp.erase(ball[b]);
                    count--;
                   }
        
                }
            ball[b]=col;
                mp[col]++;
                if(mp[col]==1){
                    count++;
                }
            
          ans.push_back(count);
        }
        return ans;
    }
};