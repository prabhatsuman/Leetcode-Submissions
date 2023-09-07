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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        for(int i=0;i<left-1;i++)
        {
            prev=prev->next;
            curr=curr->next;
        }
        ListNode* subHead=curr;
        ListNode* preNode=NULL;
        for(int i=0;i<right-left+1;i++)
        {
            ListNode* next=curr->next;
            curr->next=preNode;
            preNode=curr;
            curr=next;
        }
        subHead->next=curr;
        prev->next=preNode;
        return dummy->next;

    }
};