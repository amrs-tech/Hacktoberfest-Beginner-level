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
    ListNode* reverseList(ListNode* head) {
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         while (curr != NULL)
//         {
//             ListNode* temp=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=temp;
//         }
//         return prev;
//     
        if(!head -> next)
            return head;
        ListNode* temp = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return temp;
    }
};
