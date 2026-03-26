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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // 1. Split the list into two halves using Fast & Slow pointers
        ListNode* temp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'temp' is the end of the first half, disconnect it
        temp->next = nullptr;

        // 2. Recursively sort each half
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // 3. Merge the sorted halves
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Attach any remaining nodes
        if (l1) current->next = l1;
        if (l2) current->next = l2;

        return dummy.next;
    }
};