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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        
        while(lists.size() > 1){
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* merge(ListNode *p, ListNode *q){
        if(!p) return q;
        if(!q) return p;
        
        ListNode* temp=NULL;
        if(p->val<q->val) 
        {
            temp =p;
            temp->next = merge(p->next,q);
        }
        else 
        {
            temp = q;
            temp->next = merge(p,q->next);
        }
        return temp;        
    }
};