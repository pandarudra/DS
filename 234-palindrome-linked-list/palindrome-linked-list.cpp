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
    int getlen(ln node) {
        int len = 0 ;
        while(node != nullptr) {
            len++ ;
            node = node->next ;
        }
        return len ;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true ;

        // [1 ,0 , 1]
        //  0  1   2

        ln slow = head ;
        ln fast = head ;

        int len = getlen(head) ;

        while(fast != nullptr && fast->next != nullptr) {
            if(slow->next) slow = slow->next ;
            if(fast->next) fast = fast->next ;
            if(fast->next) fast = fast->next ;
            
        }

        // slow = 1 , fast = 2


        stack<int> st ;
        ln node = head ;

        while(node != slow) {
            st.push(node->val) ;
            node = node->next ;
        }

        // node = 0 
        // st = [1]

        if(len % 2 != 0) slow = slow->next ;

        while(!st.empty() && slow != nullptr) {
            if(!st.empty() && slow->val == st.top()) {
                st.pop() ;
                slow = slow->next ;
                continue ;
            }
            return false ;
        }
        return true ;
    }
};