class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextptr;
        int count=0;
        while(curr!=NULL && count<2)
        {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            count++;
        }
        if(nextptr!=NULL)
        {
            head->next = swapPairs(nextptr);
        }
        return prev;
    }
};
