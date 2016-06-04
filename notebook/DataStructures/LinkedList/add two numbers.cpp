/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Digits are stored in a reverse order
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

// The digits are NOT stored in reverse order

// We first compute the length of l1 and l2, and align them using recursions and their lengths, 
// add digits from the end of linked lists to the beginning
pair<ListNode*,int> _add(int len1, int len2, ListNode* l1, ListNode* l2){
  pair<ListNode*,int> head;
  if(!l1&&!l2)return make_pair((ListNode*)NULL,0);
  if(len1>len2){
    head = _add(len1-1,len2,l1->next,l2);
  }
  else if(len1<len2){
    head = _add(len1,len2-1,l1,l2->next);
  }
  else{
    head = _add(len1-1,len2-1,l1->next,l2->next);
  }
  ListNode *n = new ListNode(0);
  n->next = head.first;
  int rem=0;
  if(len1==len2){
    n->val = head.second + l1->val + l2->val;
    rem = n->val/10;
    n->val%=10;
  }
  else if(len1>len2){
    // only add l1
    n->val = head.second + l1->val;
    rem = n->val/10;
    n->val%=10;
  }
  else{
    // only add l2
    n->val = head.second + l2->val;
    rem = n->val/10;
    n->val%=10;
  }
  return make_pair(n,rem);
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int len1=0,len2=0;
  ListNode *tmp=l1;
  while(tmp){
    len1++;
    tmp=tmp->next;
  }
  tmp=l2;
  while(tmp){
    len2++;
    tmp=tmp->next;
  }
  pair<ListNode*,int> head = _add(len1,len2,l1,l2);
  if(head.second==0)return head.first;
  else{
    ListNode *n = new ListNode(head.second);
    n->next = head.first;
    return n;
  }
 }
