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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //first pass store superficial copy of all of the nodes in a map 
        //the next and random point to the original map 

        unordered_map<Node*, Node*> copies;
        auto h = head;
        while(h){
            auto next = h->next;
            auto random = h->random;

            if(copies.find(h)==copies.end()){
                Node* copy = new Node(h->val);
                copy->next = next;
                copy->random = random;
                copies[h] = copy;
            }
            h = h->next;
        }

        for(auto copyPair: copies){
            auto copy = copyPair.second;
            if(copy->next){
                copy->next = copies[copy->next];
            }
            if(copy->random){
                copy->random = copies[copy->random];
            }
        }
        return copies[head];
    }
};
