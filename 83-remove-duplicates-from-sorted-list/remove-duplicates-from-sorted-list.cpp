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

using ln = ListNode ;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ln *dummy = new ln(101) ;
        ln *ptr = dummy ;
        while(head != nullptr) {
            if(ptr->val != head->val) {
                ptr->next = new ln(head->val) ;
                ptr = ptr->next ;
            }
            head = head->next ;
        }
        ptr->next = nullptr ;
        return dummy->next ;
    }
};