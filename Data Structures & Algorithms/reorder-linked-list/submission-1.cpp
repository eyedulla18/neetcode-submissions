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

    ListNode* findMiddle(ListNode* head) {
        auto tail = head;
        auto leader = head;

        while(leader && leader->next){
            tail = tail->next;
            leader = leader->next;
            if(leader){
                leader = leader->next;
            }
        }
        cout<<"middle is: "<< tail->val<<"\n";
        return tail;
    }

    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* cur = head;
        
        while(cur){
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;

    }

    void reorderList(ListNode* head) {
        auto half = findMiddle(head);
        //split the list 
        auto middle = half->next;
        half->next = nullptr;

        //reverse the second half
        middle = reverse(middle);

        //merge the head and the reversed 
        // while(head){
        //     cout<<head->val<<'\n';
        //     head = head->next;
        // }
        // cout<<"middle: \n";
        // while(middle){
        //     cout<<middle->val<<'\n';
        //     middle = middle->next;
        // }

        auto combined = head;
        head = head->next;        
        while(head && middle){
            // cout<<head->val<<'\n';
            // cout<<middle->val<<'\n';
            // head = head->next;
            // middle = middle->next;

            auto nextMiddle = middle->next;
            auto nextHead = head->next;
            combined->next = middle;
            combined->next->next = head;
            combined = combined->next->next;
            middle = nextMiddle;
            head = nextHead;
        }




    }
};
