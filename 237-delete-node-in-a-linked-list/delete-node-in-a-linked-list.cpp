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
    void deleteNode(ListNode* node) {
        ListNode *next_node = node->next ;
        while(next_node != nullptr && next_node->next != nullptr) {
            node->val = next_node->val ;
            node = next_node ;
            next_node = next_node->next ;
        }
        node->val = next_node->val ;
        node->next = nullptr ;
    }
};