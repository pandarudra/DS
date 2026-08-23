class Solution {
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr ;
        ListNode* current = node ;
        while(current != nullptr) {
            ListNode* cn = current->next ;
            current->next = prev ;
            prev = current ;
            current = cn ;
        }
        return prev ;
    }
    ListNode* getKthNode(ListNode* node , int k) {
        while(node != nullptr && --k) node = node->next ;
        if(k) return nullptr ;
        return node ;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1) ;

        ListNode* node = head ;
        dummy->next = head ;
        ListNode* dn = dummy ;


        while(node != nullptr) {
            ListNode* kn = getKthNode(node , k) ;

            if(kn == nullptr) {
                break ;
            }
            
            ListNode* knn = kn->next ;
            kn->next = nullptr ;
            dn->next = reverse(node) ;
            node->next = knn ;
            dn = node ;
            node = knn ;
        }

        return dummy->next ;
    }
};