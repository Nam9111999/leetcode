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

// DFS
class Solution {
public:
    Node* clone(Node* node, unordered_map<Node*,Node*>& mem) {
         Node* cl;
        if(mem.find(node) == mem.end() ) {
           cl = new Node(node->val);
            mem[node] = cl;
        } 
        
        for(auto x:node->neighbors) {
            if(mem.find(x) != mem.end() ) {
                cl->neighbors.push_back(mem[x]);
            }else{
                cl->neighbors.push_back(clone(x,mem));
            }
        }
        return cl;
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        if(node->neighbors.size() ==0) return new Node(node->val);
        unordered_map<Node*,Node*> mem;
        return clone(node,mem);
    }
};

// BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        if(node->neighbors.size() ==0) return new Node(node->val);
        queue<Node*> q;
        q.push(node);
        Node* copy = new Node(node -> val);
        copies[node] = copy;
        while(!q.empty()) {
            Node* cur = q.front();q.pop();
            for(auto x:cur->neighbors) {
                if(copies.find(x) == copies.end()){
                    copies[x] = new Node(x -> val, {});
                    q.push(x);
                } 
                   copies[cur] -> neighbors.push_back(copies[x]);

            }
        }
       
        return copy;
    }
    private:
        unordered_map<Node*, Node*> copies;
};
