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
        unordered_set <ListNode*> s;
        s.insert(head);
        while(head!=NULL)
        {
            if(s.count(head->next))
            {
                return true;
            }
            else{
                s.insert(head->next);
            }
            head=head->next;
            
        }
        return false;        
    }
};