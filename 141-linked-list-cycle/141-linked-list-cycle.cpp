/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        
        ListNode* p = head->next, *q = head;
        while(p && p->next && q){
            p = p->next->next;
            q = q->next;
            if(p==q)
                return true;
        }
        return false;
    }
};

