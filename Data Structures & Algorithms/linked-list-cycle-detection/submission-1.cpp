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
public:
    bool hasCycle(ListNode* head) {
        auto trail = head;
        auto leader = head; 
        while(trail && leader){
            trail = trail->next;
            leader = leader->next;
            if(leader){
                leader = leader->next;
            }

            if(!trail && !leader){
                return false;
            }
            if(trail==leader){
                return true;
            }
        }
        return false;
    }
};
