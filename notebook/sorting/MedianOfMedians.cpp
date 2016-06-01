int partition(vector<int> &v, int s, int e, int pivot){
  swap(v[s],v[pivot]);
  int head=s+1,tail=e;
  while(head<=tail){
    while(head<=tail&&v[head]<=v[s])head++;
    while(head<=tail&&v[tail]>v[s])tail--;
    if(head<=tail){
      swap(v[head],v[tail]);
      head++;
      tail--;
    }
  }
  swap(v[s],v[tail]);
  return tail;
}

/*
  Return the index of the kth(one-index) smallest element
  v= {1 2 3 4 5 6}
  2nd smallest element = 2

  Worst case performance	O(n)
  Best case performance	O(n)
  Worst case space complexity	O(log n)
*/
int medianOfMedians(vector<int> &v, int s, int e, int k){
  // if the partition length is less than or equal to 5
  // we can sort and find the kth element of it
  // this way we can find the median of n/5 partitions
  if(e-s+1 <= 5){
    sort(v.begin()+s, v.begin()+e+1);
    return s+k-1;
  }
    
  // if array is bigger 
  // we partition the array in subarrays of size 5
  // no. of partitions = n/5 = (e+1)/5
  // iterate through each partition
  // and recursively calculate the median of all of them
  // and keep putting the medians in the starting of the array
  for(int left=s;left<=e;left+=5){
    int right = left+4<=e?left+4:e;
    swap(v[medianOfMedians(v,left,right,(right-left+1)/2+1)],v[s+(left-s)/5]);
  }
  // now we have array 
  // a[0] = median of 1st 5 sized partition
  // a[1] = median of 2nd 5 sized partition
  // and so on till n/5
  // to find out the median of these n/5 medians
  // we need to select the n/10th element of this set (i.e. middle of it)
  int pivot =  medianOfMedians(v, s, s+(e-s)/5,((e-s)/5+1)/2+1);
  pivot = partition(v,s,e,pivot);
  if(pivot-s+1==k){
    return pivot;
  }
  else if(k<pivot-s+1){
    return medianOfMedians(v,s,pivot-1,k);
  }
  else{
    return medianOfMedians(v,pivot+1,e,k-(pivot-s+1));
  }
}
