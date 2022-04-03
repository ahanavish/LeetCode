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
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        ListNode* root;
        if(list1->val<list2->val){
            root = list1;
            list1 = list1->next;
        }
        else{
            root = list2;
            list2 = list2->next;
        }
        
        ListNode* curr=root;
        while(list1&&list2){
            if(list1->val<list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        if(list1==NULL)
            curr->next = list2;
        else if(list2==NULL)
            curr->next = list1;
        
        return root;
    }
};
