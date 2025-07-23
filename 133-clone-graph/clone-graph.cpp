/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* clone_node=new Node(node->val);
        unordered_map<Node*,Node*>mp;
         mp[node]=clone_node;

        queue<pair<Node*,Node*>>q;
        q.push({node,clone_node});
        while(!q.empty()){
         Node*curr=q.front().first;
         Node*curr2=q.front().second;
         q.pop();
        for(auto i:curr->neighbors){
           if(mp.count(i)==0){
           Node* temp=new Node(i->val);
           curr2->neighbors.push_back(temp);
           mp[i]=temp;
           q.push({i,temp});
           }
           else{
            curr2->neighbors.push_back(mp[i]);
           }
        }
    }
    return clone_node;
    }
};