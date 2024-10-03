/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // Check if there are at least k nodes to reverse
        ListNode curr = head;
        int count = 0;
        
        // Find if there are at least k nodes remaining
        while (curr != null && count < k) {
            curr = curr.next;
            count++;
        }
        
        // If we have found at least k nodes, we proceed to reverse
        if (count == k) {
            // Reverse first k nodes
            ListNode prev = null;
            ListNode next = null;
            curr = head;
            count = 0;
            
            while (curr != null && count < k) {
                next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            
            // Now `prev` is the new head of the reversed section
            // The `head` becomes the tail after reversal
            // Recursively call reverseKGroup for the rest of the list and connect it
            head.next = reverseKGroup(next, k);
            
            // Return the new head of the reversed list
            return prev;
        }
        
        // If we have less than k nodes, just return the original head
        return head;
    }
}
