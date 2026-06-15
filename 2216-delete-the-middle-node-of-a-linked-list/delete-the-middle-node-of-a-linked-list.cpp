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
using ln = ListNode* ;
class Solution {
    pair<ln , ln> getmidinfo(ln node) {
        ln slow = node ;
        ln fast = node ;
        ln bslow = slow ;
        while(fast && fast->next) {
            if(slow->next) {
                bslow = slow ;
                slow = slow->next ;
            }
            if(fast->next) {
                fast = fast->next ;
            }
            if(fast->next) {
                fast = fast->next ;
            }
        }
        return {slow , bslow} ;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        pair<ln , ln> p = getmidinfo(head) ;
        ln bmid = p.second ;
        ln mid = p.first ;
        if(bmid == mid) return nullptr ;
        bmid->next = mid->next ;
        return head ;
    }
};