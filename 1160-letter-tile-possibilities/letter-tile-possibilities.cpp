class Solution {
public:
    void fun(set<string>&st,string tiles,vector<bool>visited,string curr){
        if(curr.size()==tiles.size()){
            st.insert(curr);
        }
        for(int i=0;i<tiles.size();i++){
            if(visited[i]==false){
                curr+=tiles[i];
                st.insert(curr);
                visited[i]=true;
                fun(st,tiles,visited,curr);
                visited[i]=false;
                curr.pop_back();
            }
        }
        return ;
    }
    int numTilePossibilities(string tiles) {
    set<string>st;
    vector<bool>visited(tiles.size(),false);
    string curr="";
    fun(st,tiles,visited,curr);
    return st.size();
    }

};