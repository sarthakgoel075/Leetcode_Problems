/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string fun(TreeNode* root){
        if(root==NULL)return "null";
        string ans=to_string(root->val);
        ans+=",";
        ans+=fun(root->left);
         ans+=",";
        ans+=fun(root->right);
        return ans;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL){
            ans+="null";
            return ans;
        }
        return fun(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* buildTree(queue<string> &q) 
    {
        if(q.empty())return NULL;
        string s = q.front();
        q.pop();
        
        if(s == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    TreeNode* deserialize(string data) 
    {
        string s = "";
        queue <string> q;
        for(char c: data) 
        {
            if(c == ',') 
            {
                q.push(s);
                s = "";
            }
            else
                s += c;
        }
        
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));