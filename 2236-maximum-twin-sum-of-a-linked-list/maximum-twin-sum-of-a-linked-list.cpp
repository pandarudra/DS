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
    ln getmid(ln node) {
        ln slow = node ;
        ln fast = node ;

        while(fast && fast->next) {
            if(slow->next) slow = slow->next ;
            if(fast->next) fast = fast->next ;
            if(fast->next) fast = fast->next ;
        }
        return slow ;
    }
public:
    int pairSum(ListNode* head) {
        ln mid = getmid(head) ;
        
        ln node = head ;
        stack<int> st ;
        
        while(node != mid) {
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