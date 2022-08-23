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
    bool isPalindrome(ListNode* head) {
        ListNode *endOfFirstHalf = getHalfPointer(head);
        ListNode *head2 = reverse(endOfFirstHalf);
        
        ListNode *t1 = head;
        ListNode *t2 = head2;
        
        while(t2 != nullptr)
        {
            if(t1->val != t2->val)
                return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }
    
    ListNode *reverse(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = nullptr;
        ListNode *r = nullptr;
        
        while(p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
    
    ListNode* getHalfPointer(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != nullptr and fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
