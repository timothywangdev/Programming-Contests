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
    ListNode *merge(ListNode *a, ListNode *b){
        ListNode *dummy=new ListNode(0),*cur;
        cur=dummy;
        while(a&&b){
            if(a->val<=b->val){
                cur->next=a;
                a=a->next;
            }
            else{
                cur->next=b;
                b=b->next;
            }
            cur=cur->next;
        }
        cur->next=a?a:b;
        return dummy->next;
    }
    // Returns floor(n/2) (0-based)
    ListNode *middle(ListNode *head){
        ListNode *slow=head, *fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode *mid=middle(head);
        ListNode *secondHalf=mid->next;
        mid->next=NULL;
        return merge(sortList(head),sortList(secondHalf));
    }
};
