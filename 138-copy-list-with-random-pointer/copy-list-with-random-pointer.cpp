/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#define umap unordered_map

class Solution {
    umap<Node* , Node*> mp ;

    void createLLWithNext(Node* node , Node* head) {
        if(head == nullptr) {
            node->next = nullptr ;
            return ;
        }
        node->next = new Node(head->val) ;
        mp[head] = node->next ;
        createLLWithNext(node->next , head->next) ;
    }
    void modifyLLWithRand(Node* node , Node* head) {
        if(head == nullptr) return ;
        if(head->random != nullptr) node->random = mp[head->random] ;
        modifyLLWithRand(node->next , head->next) ;
    }
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1) ;
        createLLWithNext(dummy , head) ;
        modifyLLWithRand(dummy->next , head) ;
        return dummy->next ;
    }
};