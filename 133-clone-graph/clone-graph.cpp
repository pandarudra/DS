/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        unordered_map<Node*,Node*> cloneMap ;
        
        queue<Node*> q ;
        unordered_set<Node*> s ;
        q.push(node) ;
        s.insert(node) ;
        cloneMap[node] = new Node(node->val) ;

        while(!q.empty()){
            Node* n = q.front() ;
            q.pop() ;
            for(auto &neighbor : n->neighbors){
                if(!s.count(neighbor)){
                    q.push(neighbor) ;
                    cloneMap[neighbor] = new Node(neighbor -> val) ;
                    s.insert(neighbor) ;
                }
                cloneMap[n]->neighbors.push_back(cloneMap[neighbor]) ;
            }
        }


        return cloneMap[node] ;
    }
};