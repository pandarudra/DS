class Solution {
    int getdiff(ListNode* a, ListNode* b) {
        int len1 = 0, len2 = 0;

        while(a) {
            len1++;
            a = a->next;
        }

        while(b) {
            len2++;
            b = b->next;
        }

        return len1 - len2;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int d = getdiff(headA, headB);

        if(d > 0) {
            while(d--) headA = headA->next;
        } else {
            while(d++) headB = headB->next;
        }

        while(headA && headB) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};