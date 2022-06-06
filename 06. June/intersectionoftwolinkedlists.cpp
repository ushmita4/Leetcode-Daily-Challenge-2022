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
       ListNode *a=headA,*b=headB;
       int ca=0,cb=0;
        for(ListNode *curr=headA;curr!=NULL;curr=curr->next)
            ca++;
        for(ListNode *curr=headB;curr!=NULL;curr=curr->next)
            cb++;
        while(ca>cb){
            a=a->next;
            ca--;
        }
        while(cb>ca) {
            cb--;
            b=b->next;
        }
        while(a!=b) {
            a=a->next;
            b=b->next;
        }
        return a;
    }
};
