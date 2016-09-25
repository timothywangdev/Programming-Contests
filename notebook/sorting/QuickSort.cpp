template <class RanIt, class Comparator>
void quicksort(RanIt first, RanIt last, Comparator cmp){
  RanIt pivot = first, head = first+1, tail=last-1;
  while(head<=tail){
    while(head<=tail&&!(*cmp)(*pivot, *head))head++;
    while(head<=tail&&(*cmp)(*pivot, *tail))tail--;
    if(head<=tail){
      swap(*head, *tail);
      head++;
      tail--;
    }
  }
  swap(*pivot, *tail);
  if(first<tail){
    quicksort(first, tail, cmp);
  }
  if(tail+1<last){
    quicksort(tail+1,last,cmp);
  }
}
