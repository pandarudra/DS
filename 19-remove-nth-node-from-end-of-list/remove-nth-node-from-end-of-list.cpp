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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr ;
        ptr = head ;

        // find size
        int sz = 0 ;
        while(ptr != nullptr) {
            sz++ ;
            ptr = ptr->next ;
        }

        ptr = head ;

        int i = 0 ;
        int k = sz - n ;

        if(k == 0) {
            ptr = head->next ;
            head->next = nullptr ;
            return ptr ;
        }

        while(i < k - 1 && ptr != nullptr) {
            ptr = ptr->next ;
            i++ ;
        }

        ptr->next = ptr->next->next ;

        return head ;
    }
};