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
        
        while(r1 != nullptr || r2 != nullptr) {

            int a = 0 , b = 0 ;

            if(r2 != nullptr) b = r2->val ;
            if(r1 != nullptr) a = r1->val ;

            int rval = a + b + lov ;
            lov = rval / 10 ;

            node->next = new ListNode(rval % 10) ;
            node = node->next ;

            if(r1 != nullptr) r1 = r1->next ;
            if(r2 != nullptr) r2 = r2->next ;
        }


        if(lov) {
            node->next = new ListNode(lov) ;
        }

        return result->next ;
    }
};