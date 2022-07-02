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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a,*b;
        a=headA;
        b=headB;
        if(a->next==NULL && b->next==NULL){
            if(a==b){
                return a;
            }
            else{
                return NULL;
            }
        }
        int l1=0,l2=0;
        while(a!=NULL){
            a=a->next;
            l1++;
        }
        while(b!=NULL){
            b=b->next;
            l2++;
        }
        if(l1>l2){
            a=headA;
            int c=0;
            while(c<l1-l2 && a->next!=NULL){
                a=a->next;
                c++;
            }
            b=headB;
        }
        else{
            b=headB;
            int c=0;
            while(c<l2-l1 && b->next!=NULL){
                b=b->next;
                //cout<<b->val<<" ";
                c++;
            }
            a=headA;
        }
        //cout<<a->val<<b->val;
        while(a!=NULL && b!=NULL){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};