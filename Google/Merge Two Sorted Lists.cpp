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

/*
    Time complexity: O(min(n,m))
    Space: O(1)

*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        if(!list1 && list2) return list2;
        if(list1 && !list2) return list1;
        
        if(list1->val < list2->val) return mergeSorted(list1, list2);
        else return mergeSorted(list2, list1);
    }
    
    ListNode* mergeSorted(ListNode* list1, ListNode* list2) {
        // list 1 is now gauranteed to start off smaller or equal to list2
        
        // if list 2 is empty, return head
        // if list 1 is empty, add curr 2 to list 1
        
        // if the curr2 val is equal to curr1, add as next to curr of list 1
        // if curr2 is greater than curr 1 and less than curr1->next
        
        // augment both list 1 and 2
        
        ListNode *curr1 = list1, *curr2 = list2;
        
        while(curr1 || curr2) {
            if(!curr2) return list1;
            else if(!curr1->next) {
                curr1->next = curr2;
                curr2 = curr2->next;
                curr1 = curr1->next;
                return list1;
            }
            else if(curr2->val == curr1->val || (curr2->val > curr1->val && curr2->val < curr1->next->val)) {
                ListNode *t = curr2->next;
                curr2->next = curr1->next;
                curr1->next = curr2;
                curr2 = t;
            }
            
            if(curr1->next) curr1 = curr1->next;
        }
        
        return list1;
    }
};
