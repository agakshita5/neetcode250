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
        if(!head || !head->next) return nullptr;

        ListNode* dummy = new ListNode(0); // dummy node
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // fast to be at n+1 steps ahead from slow
        int i = 1;
        while(i <= n+1){
            fast = fast->next;
            i++;
        }
        
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        // toDel = slow->next
        ListNode* toDel = slow->next;
        slow->next = toDel->next;
        delete toDel;
    
        return dummy->next;
    }
};
