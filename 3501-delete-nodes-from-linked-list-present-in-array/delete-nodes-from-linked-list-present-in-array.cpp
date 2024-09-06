class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        ListNode* temp = head;
        ListNode* pre = nullptr;  // Start with pre as nullptr

        while (temp) {
            if (mp.count(temp->val) > 0) {
              
                if (temp == head) {
                    head = head->next;  
                } else {
                    pre->next = temp->next;  
                }
            } else {
               
                pre = temp;
            }
            temp = temp->next;  
        }

        return head;
    }
};
