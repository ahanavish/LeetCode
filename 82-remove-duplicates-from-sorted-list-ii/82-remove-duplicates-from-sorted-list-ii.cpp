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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode *nd=head,*prev=new ListNode(-500),*rd;
        rd=prev;
        prev->next=head;
        int k=-500;
       while(nd&&nd->next)
       {
            if(nd->val==nd->next->val||nd->val==k)
           {
             
           }
           else
           {
              prev->next=nd;
              prev=nd;
           }
        k=nd->val;
        nd=nd->next;
       }
        if(nd&&nd->val!=k)
        {
            prev->next=nd;
        }
        else
        {
            prev->next=NULL;
        }
        return rd->next;
    }
};