class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        deque<ListNode*> dq ;
        ListNode* dummy = new ListNode(-1) ;

        ListNode* node = head ;
        ListNode* dn = dummy ;
        while(node != nullptr) {
            if(dq.size() == k) {
                while(!dq.empty()) {
                    dn->next = dq.back() ;
                    dn = dn->next ;
                    dq.pop_back() ;
                }
            }
            dq.push_back(node) ;
            node = node->next ;
        }

        if(dq.size() == k) {
            while(!dq.empty()) {
                dn->next = dq.back() ;
                dq.pop_back() ;
                dn = dn->next ;
            }
        }


        while(!dq.empty()) {
            dn->next = dq.front() ;
            dq.pop_front() ;
            dn = dn->next ;
        }
        dn->next = nullptr ;
        return dummy->next ;
    }
};