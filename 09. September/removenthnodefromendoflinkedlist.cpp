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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* prev = new ListNode(-1);
        int size = 0;
        while(temp){
            temp=temp->next;
            size++;
        }

        n=size-n;
        cout<<n;
        temp = head;
        while(temp){
            
            if(n==0){
               if(prev->val==-1) head=head->next; 
                prev->next = temp->next;
                
                break;
            }
            prev = temp;
            temp = temp->next;
            n--;
        }
        return head;
    }
};
