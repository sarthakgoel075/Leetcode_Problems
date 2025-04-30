/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto it:lists)
        {
            if(it){
            pq.push({it->val,it});
            cout<<it->val<<endl;}
        }
        ListNode* prev=nullptr;
        ListNode* head=nullptr;
        if(!pq.empty())
        {
            auto it=pq.top();
            prev=it.second;
            head=it.second;
            if(prev->next)
            pq.push({prev->next->val,prev->next});
            pq.pop();
        }
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ListNode* node=it.second;
           if(node->next)
           pq.push({node->next->val,node->next});
           prev->next=node;
           prev=node;
            } 
            return head;
    }
};