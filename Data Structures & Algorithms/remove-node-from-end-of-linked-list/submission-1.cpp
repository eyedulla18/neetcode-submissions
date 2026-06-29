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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto forward = head;
        auto trail = head;
        for(int i=0; i<n; ++i){
            // cout<<"move forward by 1 \n";
            forward = forward->next;
        }

        while(forward && forward->next){
            forward = forward->next;
            trail = trail->next;
        }
        
        if(!forward){
            cout<<"return everything but the head";
            return head->next;
        }
        cout<<trail->val;
        cout<<forward->val;
        trail->next = trail->next->next;
        return head;
    }
};
