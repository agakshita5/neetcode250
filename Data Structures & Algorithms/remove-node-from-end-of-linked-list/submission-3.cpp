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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* nx;
        while(head){
            nx = head->next;
            head->next = prev;
            prev = head;
            head = nx;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse ll
        // for loop till u reach n
        // toDel node, and removal

        if(!head || !head->next) return nullptr; // empty list or 1 node only

        ListNode* h = reverseLL(head);

        if(n == 1) h = h->next;
        else{
            ListNode* curr = h;
            ListNode* prev;
            int i=1;

            while(i<n && curr){
                prev = curr;
                curr = curr->next;
                i++;
            }
            // after loop ends -> curr = toDel node and prev is node pointing to toDel
            // ListNode* toDel = curr;
            prev->next = curr->next;
            delete curr;
        }

        ListNode* res = reverseLL(h);      
        return res;
    }
};
