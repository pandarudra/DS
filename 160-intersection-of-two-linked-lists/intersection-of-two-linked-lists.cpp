using ln = ListNode ;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA != nullptr) {
            ln *temp = headB ;
            while(temp != nullptr) {
                if(temp == headA) return headA ;
                temp = temp->next ;
            }
            headA = headA->next ;
        }
        return nullptr ;
    }
};