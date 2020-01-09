// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Recursive
class Solution {
public:
    unordered_map<Node*, Node*> hash;
    
    Node* cloneGraph(Node* node) {
        if(!hash.count(node)) {
            hash[node] = new Node(node->val, node->neighbors);
            for(int i = 0; i < node->neighbors.size(); i++)
                hash[node]->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        
        return hash[node];
    }
};

// Iterative
class Solution {
public:
    unordered_map<Node*, Node*> hash;
    
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        
        Node *newNode = new Node();
        newNode->val = node->val;
        hash[node] = newNode;
        
        q.push(node);
        while(!q.empty()) {
            Node *aux = q.front();
            q.pop();
        
            for(Node* n : aux->neighbors) {
                if(!hash.count(n)) {
                    Node* tmp = new Node();
                    tmp->val = n->val;
                    hash[n] = tmp;
                    q.push(n);
                }
                hash[aux]->neighbors.push_back(hash[n]);
            }
        }
        
        return hash[node];
    }
};