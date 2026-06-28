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

    ListNode* reverse(ListNode* head){
        //[3, 4, 5, 6]
        ListNode* cur = head;
        ListNode* prev = nullptr;
        
        while(cur){
            auto nextCopy = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextCopy;
        }
        head = prev;
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<'\n';
        return prev;
    }

    void reorderList(ListNode* head) {
        auto fast = head;
        auto slow = head;

        while(fast && slow){
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            else{
                break;
            }
            slow = slow->next;
        }
        
        auto second = slow->next;
        slow->next = nullptr;
        cout<<"mid point="<<slow->val<<'\n';
        auto l2 = reverse(second);
        //[0,1,2,6,5,4,3]
        //0,6,1,5,2,4,3

        auto l1 = head;
        while(l2){
            auto l1Next = l1->next;
            auto l2Next = l2->next;
            l1->next = l2;
            l2->next = l1Next;
            l1=l1Next;
            l2=l2Next;
            
        }


    }
};
