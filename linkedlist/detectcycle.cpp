/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return false;
        }
        ListNode *a,*b;
        a=head;
        b=head;
        while(a!=NULL && a->next!=NULL){
            a=a->next->next;
            b=b->next;
            if(a==b){
                return true;
            }
        }
        return false;
    }
};

*/