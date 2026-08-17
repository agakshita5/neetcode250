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
        while(j && j->next){
            i = i->next;
            j = j->next->next;
        }
        // when j == null or j->next == null -> i is the middle node
        // reverse from middle node to end node
        ListNode* leftHead = head;
        ListNode* rightHead= reverseLL(i);
        ListNode* c1 = leftHead;
        ListNode* c2 = rightHead;

        ListNode* st = new ListNode(0); // dummy
        ListNode* end = st;
        while(c1 && c2 && c1 != c2){
            end->next = c1;
            end = end->next;
            c1 = c1->next;
            
            end->next = c2;
            end = end->next;
            c2 = c2->next;
        }
    }
};
