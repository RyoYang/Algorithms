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
    struct cmp{
        bool operator ()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(auto &l: lists) if(l) pq.push(l);

        while(pq.size())
        {
            tmp->next = pq.top();
            if(pq.top()->next) pq.push(pq.top()->next);
            pq.pop();
            
            tmp = tmp->next;
        }
        return dummy->next;
    }
};