/*
  Iterative
*/
ListNode* reverseList(ListNode* head) {
  if(!head)return head;
  ListNode *pre=NULL;
  while(head){
    ListNode *ne=head->next;
    if(!pre){
      head->next=NULL;
    }
    else{
      head->next=pre;
    }
    pre=head;
    head=ne;
  }
  return pre;
}

/*
  recursive
  return <head,tail>
*/
pair<ListNode*,ListNode*> reverse(ListNode* head) {
  if(!head||!head->next)return make_pair(head,head);
  pair<ListNode*,ListNode*> t=reverse(head->next);
  head->next=NULL;
  t.second->next=head;
  return make_pair(t.first,head);
}
