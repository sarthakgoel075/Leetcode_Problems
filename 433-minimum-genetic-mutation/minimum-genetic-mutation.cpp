class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,int>mp;
        unordered_map<string,int>visited;

        int level=0;
        for(auto i:bank){
            mp[i]++;
        }
        queue<string>q;
        q.push(startGene);
        while(!q.empty()){
             int n=q.size();
             while(n--){
            string curr=q.front();
            q.pop();
           if(curr==endGene){
            return level;
           }

            vector<char>chr={'A','C','G','T'};
            for(auto ch:chr){
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    temp[i]=ch;
                    if(mp.count(temp)>0 && visited.count(temp)==0){
                     q.push(temp);
                     visited[temp]++;
                    }
                }
            }
        }
        level++;
        }
        return -1;
    }
};