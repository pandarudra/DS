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
    int getlen(ListNode* node) {
        int len = 0 ;
        while(node != nullptr) {
            len++ ;
            node = node->next ;
        }
        return len ;
    }
    ListNode* getmid(ListNode* node) {
        ListNode *slow , *fast ;
        slow = node , fast = node ;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
    }
    ListNode* reversell(ListNode* head) {
        ListNode* prev = nullptr ;
        while(head != nullptr) {
            ListNode* cn = head->next ;
            head->next = prev ;
            prev = head ;
            head = cn ;
        }
        return prev ;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true ;
        int n = getlen(head) ;
        ListNode* md = getmid(head) ;
        if(n % 2 != 0) md = md->next ;
        ListNode* nh = reversell(md) ;

        ListNode* nhn = nh ;
        ListNode* node = head ;
        
        while(node != nullptr && nhn != nullptr) {
            if(node->val != nhn->val) return false ;
            node = node->next ;
            nhn = nhn->next ;
        }


        ListNode* x = reversell(nh) ;

        return true ;
    }
};