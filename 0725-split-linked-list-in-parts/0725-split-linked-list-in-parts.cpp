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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int size=0;
        ListNode* temp=head;
        while(temp)
        {
            size++;
            temp=temp->next;
        }
        int q=size/k;
        // cout<<q<<endl;
        int rem=size%k;
        // cout<<rem<<endl;
        temp=head;
        for(int i=0;i<k;i++)
        {
            ans[i]=temp;
            ListNode *prev=NULL;
            for(int j=0;j<q;j++)
            {
                prev=temp;
                temp=temp->next;
            }
            if(rem>0)
            {
                prev=temp;
                temp=temp->next;
                rem--;
            }
            if(prev)
            {
                prev->next=NULL;
            }
        }
        
        return ans;
    }
};