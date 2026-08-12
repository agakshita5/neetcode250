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
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        if(!curr1) return curr2;
        if(!curr2) return curr1;
        
        ListNode* st;
        ListNode* end;

        if(curr1->val <= curr2->val){
            st = curr1;
            end = curr1;
            curr1 = curr1->next;
        }else{
            st = curr2;
            end = curr2;
            curr2 = curr2->next;
        }
        
        while(curr1 && curr2){
            if(curr1->val <= curr2->val){ // c1 < c2
                end->next = curr1;
                curr1 = curr1->next;
                end = end->next;
            }
            else{ // c2 < c1
                end->next = curr2;
                curr2 = curr2->next;
                end = end->next;
            }
        }
        if(curr1){
            end->next = curr1;
        }
        if(curr2){
            end->next = curr2;
        }
        return st;
    }
};
