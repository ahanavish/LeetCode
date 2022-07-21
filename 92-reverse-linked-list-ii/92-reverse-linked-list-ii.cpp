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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        
        ListNode* last = head;
        
        for(int i=1; i<left-1; i++)
            last=last->next;
        
        ListNode *prev;
        if(left==1)
            prev=head; 
        else
            prev=last->next;
        
        ListNode *store=prev, *curr=prev->next, *nextt=curr->next;
        
        for(int i=0; i<right-left; i++){
            curr->next = prev;
            prev = curr;
            curr = nextt;
            if(nextt)
                nextt = nextt->next;
        }
        
        if(left==1)
            head = prev;
        else
            last->next = prev;
        store->next = curr;
        return head;
    }
};

