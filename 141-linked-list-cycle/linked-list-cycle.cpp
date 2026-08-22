class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st ;
        ListNode* node = head ;
        while(node != nullptr) {
            if(st.count(node)) return true ;
            st.insert(node) ;
            node = node->next ;
        }
        return false ;
    }
};