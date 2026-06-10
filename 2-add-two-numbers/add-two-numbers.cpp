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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1) ;

        int lov = 0 ;
        ListNode* r1 = l1 , *r2 = l2 ;

        ListNode* node = result ;  
        
        while(r1 != nullptr && r2 != nullptr) {
            int rval = r1->val + r2->val + lov ;
            int nodevalue = rval % 10 ;
            lov = rval / 10 ;
            node->next = new ListNode(nodevalue) ;
            node = node->next ;
            r1 = r1->next ;
            r2 = r2->next ;
        }

        while(r1 != nullptr) {
            int rval = r1->val + lov ;
            node->next = new ListNode(rval % 10) ;
            lov = (rval / 10) ;
            node = node->next ;
            r1 = r1->next ;
        }

        while(r2 != nullptr) {
            int rval = r2->val + lov ;
            node->next = new ListNode(rval % 10) ;
            lov = (rval / 10) ;
            node = node->next ;
            r2 = r2->next ;
        }

        if(lov) {
            node->next = new ListNode(lov) ;
        }

        return result->next ;
    }
};