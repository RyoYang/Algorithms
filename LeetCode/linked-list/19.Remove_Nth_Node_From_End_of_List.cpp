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

        if(!head || n <= 0) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* fast = dummy, *slow = dummy;

        for(int i = 0; i < n; i++) fast = fast -> next;

        if(!fast) return nullptr;

        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};