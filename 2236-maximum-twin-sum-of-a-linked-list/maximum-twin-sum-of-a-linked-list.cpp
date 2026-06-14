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
#define all(v) (v).begin(),(v).end()
using ln = ListNode* ;
class Solution {
    pair<ln , int> getmid(ln node) {
        ln slow = node ;
        ln fast = node ;
        int len = 0 ;
        while(fast && fast->next) {
            if(slow->next) slow = slow->next ;
            if(fast->next) fast = fast->next ;
            if(fast->next) fast = fast->next ;
            len++ ;
        }
        return {slow , 2 * len} ;
    }
public:
    int pairSum(ListNode* head) {
        pair<ln , int> p = getmid(head) ;
        int n = p.second ;
        ln mid = p.first ;
        vector<int> sum(n / 2) ;
        
        ln node = head ;
        for(int i = 0 ; i < n / 2 ; i++) {
            sum[i] = node->val ;
            node = node->next ;
        }
        for(int i = (n / 2) - 1 ; i >= 0 ; i--) {
            sum[i] += mid->val ;
            mid = mid->next ;
        }

        return *max_element(all(sum)) ;
    }
};