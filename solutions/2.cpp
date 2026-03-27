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
        ListNode* res = new ListNode(0);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* temp = res;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int sum = carry;

            if (temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            temp->val = sum % 10;
            carry = sum / 10;

            if (temp1 != NULL || temp2 != NULL || carry != 0) {
                temp->next = new ListNode(0);
                temp = temp->next;
            }
        }

        return res;
    }
};