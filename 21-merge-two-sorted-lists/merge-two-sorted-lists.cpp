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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *r1 , *r2 ;
        r1 = list1 , r2 = list2 ;
        ListNode *d = new ListNode(-1) ;

        ListNode* f = d ;

        while(r1 != nullptr && r2 != nullptr) {
            if(r1->val <= r2->val) {
                f->next = new ListNode(r1->val) ;
                r1 = r1->next ;
            }else {
                f->next = new ListNode(r2->val) ;
                r2 = r2->next ;
            }
            f = f->next ;
        }


        while(r1 != nullptr) {
            f->next = new ListNode(r1->val) ;
            f = f->next ;
            r1 = r1->next ;
        }


        while(r2 != nullptr) {
            f->next = new ListNode(r2->val) ;
            f = f->next ;
            r2 = r2->next ;
        }


        return d->next ;
    }
};