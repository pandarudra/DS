using ln = ListNode* ;
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
    pair<int , ln> getlen(ln node) {
        int len = 0 ;
        ln end = nullptr ;
        while(node != nullptr) {
            end = node ;
            len++ ;
            node = node->next ;
        }
        return {len , end} ;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head ;
        ln node = head ;
        pair<int , ln> pil = getlen(node) ;
        int n = pil.first ;
        k %= n ;
        if(k == 0) return head ;
        int nk = n - k ;

        while(nk > 1 && node != nullptr) {
            node = node->next ;
            nk-- ;
        }

        ln end = pil.second ;
        ln res = node->next ;

        node->next = nullptr ;
        end->next = head ;

        return res ;
    }
};