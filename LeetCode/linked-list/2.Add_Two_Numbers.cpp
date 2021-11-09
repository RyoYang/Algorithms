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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        if(!l1) return l2;
        if(!l2) return l1;
        int cnt = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *l3 = dummy;
        int tmp = 0;


        while(l1 && l2)
        {
            tmp = l1->val + l2->val + cnt;
            
            l3 -> next = new ListNode(tmp%10);
            
            cnt = tmp/10;
            tmp = 0;
            l1 = l1 -> next;
            l2 = l2 -> next;
            l3 = l3 -> next;
        }

        while(l1)
        {
            tmp = l1->val + cnt;
            l3 -> next = new ListNode(tmp%10);
            cnt = tmp/10;
            l1 = l1 -> next;
            l3 = l3->next;
            tmp = 0;
        } 

        while(l2)
        {
            tmp = l2->val + cnt;
            l3 -> next = new ListNode(tmp%10);
            cnt = tmp/10;
            l2 = l2 -> next;
            l3 = l3->next;
            tmp = 0;
        }

        while(cnt)
        {
            l3 -> next = new ListNode(cnt);
            l3 = l3->next;
            cnt /=10;
        }

        return dummy->next;
    }
};
