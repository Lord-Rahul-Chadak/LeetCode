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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next != NULL){
            ListNode* daal = new ListNode(gcd(temp->val, temp->next->val));

            daal->next = temp->next;
            temp->next = daal;
            temp = temp->next->next;
        }

        return head;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
};