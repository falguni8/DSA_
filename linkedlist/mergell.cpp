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
        ListNode dummy = ListNode(0);
        ListNode* ans = &dummy;
        
        while(list1 && list2){
            if(list1 -> val < list2 -> val){
                ans -> next = list1;
                list1 = list1 -> next;
            }
            else{
                ans -> next = list2;
                list2 = list2 -> next;
            }
            ans = ans -> next;
        }
        
        ans -> next = list1 ? list1 : list2;
        
        return dummy.next;
        
    }
};
///////////////////////////////////////////////////////////////////////
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
       ListNode *result;
        if(list1==NULL && list2==NULL){
            return result;
        }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<list2->val){
            result=list1;
            result->next=mergeTwoLists(list1->next,list2);
        }
        else{
            result=list2;
            result->next=mergeTwoLists(list1,list2->next);
        }
        return result;
    }
};