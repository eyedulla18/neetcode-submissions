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
        
        if(!node){
            return node;
        }

        //make a copy of each pointer and store it in a map 
        unordered_map<Node*, Node*> copyUmp;
        vector<Node*> search;
        search.push_back(node);
        while(!search.empty()){
            Node* cur = search.back();
            search.pop_back();
            if(copyUmp.find(cur)!=copyUmp.end()){
                continue;
            }
            Node* copy = new Node();
            copy->val = cur->val;
            copy->neighbors = cur->neighbors;
            copyUmp[cur] = copy;
            //push all of the neighbors into the search
            for(auto n: cur->neighbors){
                search.push_back(n);
            }
        }

        //update the neighbors nodes in the copies 
        cout<<"ump size: "<<copyUmp.size()<<'\n';
        for(auto copyPair: copyUmp){
            //does this make a copy?
            // vector<Node*> neighbors = copyPair.second->neighbors;
            // for(int i=0; i<neighbors.size(); ++i){
            //     auto neighbor = neighbors[i];
            //     neighbors[i] = copyUmp[neighbor];
            // }
            for(auto& neighbor: copyPair.second->neighbors){
                neighbor = copyUmp[neighbor];
            }
        }

        // return node;
        return copyUmp[node];


    }
};
