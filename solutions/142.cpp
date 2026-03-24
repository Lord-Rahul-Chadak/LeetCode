/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* firstNodeLoop = head;

        while(fast != NULL && fast->next != NULL && fast->next->next != NULL ){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while(firstNodeLoop != slow){
                    firstNodeLoop = firstNodeLoop->next;
                    slow = slow->next;
                }
                return firstNodeLoop;
            }
        }
        return NULL;
    }
};