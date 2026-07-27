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
        if(!head || !head->next) return head ;
        ln *left , *right ;
        left = head , right = head ;
        while(right != nullptr) {
            if(right->val != left->val) {
                left = left->next ;
                left->val = right->val ;
            }
            right = right->next ;
        }
        left->next = nullptr ;
        return head ;
    }
};