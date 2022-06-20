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
        bool remainder = false;
        ListNode* head = new ListNode;
        ListNode* curr = head;

        
        if(l1 == NULL) return l2;
        else if (l2 == NULL) return l2;
        
        while(l1 != NULL || l2 != NULL) {
            ListNode* next = new ListNode;
            
            
            int val1 = 0;
            int val2 = 0;
            
            if(l1 != NULL) val1 = l1->val;
            if(l2 != NULL) val2 = l2->val;
                        
            int sum = val1 + val2;
            
            if(remainder) sum++;
            
            next->val = sum%10;
            
            if(sum/10 > 0) remainder = true;
            else remainder = false;
            
            curr->next = next;
            curr = curr->next;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        
        if(remainder) {
            ListNode* temp = new ListNode;
            temp->val = 1;
            curr->next = temp;
        }
        
        return head->next;
    }
};


/*

keep track of if remainder
added number is sum%10

18%10 = 8

loop through, until both null

right before return check if there was a remainer (and add node or not)


*/
