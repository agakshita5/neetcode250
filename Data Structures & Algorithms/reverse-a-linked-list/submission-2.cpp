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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* prev = nullptr; // A
        ListNode* curr = head;
        ListNode* nx;
        while(curr){
            // curr = A B C D stop 
            nx = curr->next; // B | C | D | E
            curr->next = prev; // A->null | B->A | C->B | D->C
            prev = curr; // A | B | C | D
            curr = nx; // B | C | D | E
        }
        return prev;
    }
};
