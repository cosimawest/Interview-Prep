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
        // have a trailing node that have n spaces between
        // by the time the leading node gets to the end, the trailing node should be at the nth from end pos
        
        ListNode *slow = head, *fast = head;
        
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        if(!fast) return head->next;
        
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};
