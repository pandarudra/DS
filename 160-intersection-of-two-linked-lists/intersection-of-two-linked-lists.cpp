/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int countLength(ListNode* node) {
        int cnt = 0 ;
        while(node != nullptr) {
            cnt++ ;
            node = node->next ;
        }
        return cnt ;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int na = countLength(headA) ;
        int nb = countLength(headB) ;

        if(na > nb) {
            int d = na - nb ;
            while(d > 0) {
                headA = headA->next ;
                d-- ;
            }
        }


        if(na < nb) {
            int d = nb - na ;
            while(d > 0) {
                headB = headB->next ;
                d-- ;
            }
        }

        while(headA != nullptr && headB != nullptr) {
            if(headA == headB) return headA ;
            headA = headA->next ;
            headB = headB->next ;
        }

        return nullptr ;
    }
};