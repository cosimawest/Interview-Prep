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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // lol i thought they were all lists at first so ummmm
        
        // pass through to find min
        // pass through to find all of that num and add
        // each add replaces the node with it's next
        // repeat
        
        // i think O(2n) aka O(n) or O(n*m) idk
        
        ListNode* head = new ListNode();
        ListNode* pointer = head;

        int curr, count = lists.size();
        
        while(count > 0) {
            count = 0;
            curr = INT_MAX;

            // find min for this pass-through
            for(auto list : lists) {
                if(list != NULL) {
                    count++;
                    curr = min(curr, list->val);
                }
            }
                       
            // add all nums that equal min and update pointer for that node in the list
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != NULL && lists[i]->val == curr) {
                    ListNode* toAdd = new ListNode;
                    toAdd->val = curr;
                    
                    pointer->next = toAdd;
                    pointer = toAdd;

                    lists[i] = lists[i]->next;
                } 
            }
        }
        
        return head->next;
    }
};
