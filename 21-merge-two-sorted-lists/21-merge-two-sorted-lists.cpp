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
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* head=(list1->val<=list2->val)? list1:list2;
        
        ListNode *r1=list1,*r2=list2;
        
        while(r1&&r2)
        {
            if(r1->val<=r2->val )
            {
                ListNode* next=r1,*prev=r1;
                while(next)
                {
                    if(next->val>r2->val) break;
                    else
                    {
                     prev=next;
                        next=next->next;
                    }
                }
             r1=next;
                prev->next=r2;
            }
            else
            {
                ListNode* next=r2,*prev=r2;
                while(next)
                {
                    if(next->val>=r1->val) break;
                    else
                    {
                     prev=next;
                        next=next->next;
                    }
                }
             r2=next;
                prev->next=r1;
                
            }
            
            
        }
        
        return head;
        
    }
};