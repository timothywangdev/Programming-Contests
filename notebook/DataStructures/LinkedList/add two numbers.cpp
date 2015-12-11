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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rv=l1,*last_l1;
        int carry=0;
        while(l1&&l2){
            l1->val=l1->val+l2->val+carry;
            carry=l1->val/10;
            l1->val%=10;
            if(!l1->next)last_l1=l1;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1){
                l1->val=l1->val+carry;
                carry=l1->val/10;
                l1->val%=10;
                last_l1=l1;
                l1=l1->next;
            }
            if(carry){
                last_l1->next=new ListNode(carry);
            }
        }
        else if(l2){
            l1=last_l1;
            while(l2){
                l1->next=new ListNode(0);
                l1=l1->next;
                l1->val=l1->val+l2->val+carry;
                carry=l1->val/10;
                l1->val%=10;
                l2=l2->next;
            }
            if(carry){
                l1->next=new ListNode(carry);
            }
        }
        else if(carry){
            last_l1->next=new ListNode(carry);
        }
        return rv;
    }
};
