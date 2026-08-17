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
    // fast and slow pointer to get middle - i when j==null
    // reverse second half
    // iterate both halves to get final ll
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nx;
        while(curr){
            nx = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nx;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* i=head;
        ListNode* j=head;
        while(j->next && j->next->next){
            i = i->next;
            j = j->next->next;
        }
        ListNode* rightStart = i->next;
        i->next = nullptr; // leftEnd->next = null
        // when j->next == null or j->next->next == null so
        // i is the leftEnd: middle for odd; first middle for even
        // reverse from middle node to end node 

        ListNode* rightHead= reverseLL(rightStart);
        ListNode* c1 = head; 
        ListNode* c2 = rightHead;
        ListNode* nx1;
        ListNode* nx2;
        while(c2){
            nx1 = c1->next;
            nx2 = c2->next;

            c1->next = c2;
            c2->next = nx1;

            c1 = nx1;
            c2 = nx2;
        }
    }
};
