class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy(0); // Dummy node for elements less than x
        ListNode largeDummy(0); // Dummy node for elements greater than or equal to x
        ListNode* smallTail = &smallDummy;
        ListNode* largeTail = &largeDummy;

        while (head) {
            if (head->val < x) {
                smallTail->next = head;
                smallTail = smallTail->next;
            } else {
                largeTail->next = head;
                largeTail = largeTail->next;
            }
            head = head->next;
        }

        largeTail->next = nullptr; // Set the end of large list
        smallTail->next = largeDummy.next; // Connect small list to large list

        return smallDummy.next; // Return the updated head
    }
};
