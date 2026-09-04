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
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If the node is already cloned, return the cloned node
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }

        // Create a copy of the node
        Node* copy = new Node(node->val);
        cloned[node] = copy;

        // Clone all neighbors recursively
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};