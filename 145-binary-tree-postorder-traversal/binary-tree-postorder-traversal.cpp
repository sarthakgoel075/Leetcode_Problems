class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        TreeNode* temp;
        if(root==nullptr){return ans;}
        while(!st.empty()|| curr!=nullptr){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                  temp=st.top()->right;
                if(temp==NULL){
                     temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty()&& st.top()->right==temp){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }
            
        }
        return ans;
    }
};