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
        
        ln node = head ;

        stack<int> st ;
        
        for(int i = 0 ; i < n / 2 ; i++) {
            st.push(node->val) ;
            node = node->next ;
        }
        
        int mx = INT_MIN ;
        while(mid != nullptr) {
            mx = max(mx , mid->val + st.top()) ;
            st.pop() ;
            mid = mid->next ;
        }

        return mx ;
    }
};