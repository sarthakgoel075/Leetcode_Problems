class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s{wordList.begin(),wordList.end()};
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            if(word==endWord)return step;
            q.pop();
            for(int i=0;i<word.size();i++){
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=orignal;
            }
        }
        return 0;
    }
};