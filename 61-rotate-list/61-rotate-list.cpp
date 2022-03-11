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

ListNode* rotateRight(ListNode* head, int k) {
    int n=0;
    ListNode *curr=head;
    if(head==NULL || k==0){
        return head;
    }
    while(curr){
        n++;
        curr=curr->next;
    }
    k=k%n;
    if(k==0){
        return head;
    }
    int a=n-k;
    curr=head;
    ListNode *prev=NULL;
    while(a--){
        prev=curr;
        curr=curr->next;
    }
    ListNode *temp=curr;
    while(curr->next){
        curr=curr->next;
    }
    curr->next=head;
    prev->next=NULL;
    head=temp;
    return head;
    
}
};

