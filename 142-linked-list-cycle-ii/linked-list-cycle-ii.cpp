#define uset unordered_set
using ln = ListNode* ;
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
    ListNode *detectCycle(ListNode *head) {
        uset<ln> s ;
        ln node = head ;
        while(node != nullptr) {
            if(s.count(node)) return node ;
            s.insert(node) ;
            node = node->next ;
        }
        return nullptr ;
    }
};