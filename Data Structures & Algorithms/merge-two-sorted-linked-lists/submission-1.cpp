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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        ListNode* answer = nullptr;
        if(list1->val<list2->val){
            answer = list1;
            list1 = list1->next;
            cout<<"move l1 \n";
        }
        else{
            answer = list2;
            list2 = list2->next;
            cout<<"move l2 \n";
        }
        auto realAnswer = answer;

        while(list1 && list2){
            if(list1->val<list2->val){
                answer->next = list1;
                answer = answer->next;
                list1 = list1->next;
                cout<<"move l1 \n";
            }
            else{
                answer->next = list2;
                answer = answer->next;
                list2 = list2->next;
                cout<<"move l2 46 \n";
            }
        }

        if(list1){
            answer->next = list1;
        }
        else{
            answer->next = list2;
        }
        return realAnswer;
    }
};
