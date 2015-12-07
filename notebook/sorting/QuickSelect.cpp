/*
 	QuickSelect with Median of Medians
	Best, Worst, Average Time Complexity: O(n)
	Space Complexity: O(1) (We are doing it in-place)
*/
template <typename RandomIterator,
	  typename Comparator=less<typename iterator_traits<RandomIterator>::value_type>>
RandomIterator QuickSelect(RandomIterator begin, RandomIterator end, int k, Comparator comp=Comparator()){
   if(begin==end||begin+1==end)return begin;
   while(true){
      RandomIterator medianPos=begin, lastBlock=begin+((end-begin)/5)*5;
      for(RandomIterator block=begin;block!=lastBlock;block+=5, medianPos++){
	 sort(block,block+5);
	 iter_swap(medianPos,block+2);
      }
      if(lastBlock!=end){
	 sort(lastBlock,end);
	 iter_swap(medianPos,lastBlock+(end-lastBlock)/2);
	 medianPos++;
      }
      // median of medians
      RandomIterator pivot=QuickSelect(begin,medianPos,(medianPos-begin)/2,comp);
      // Back to the normal quickselect part
      iter_swap(pivot,end-1);
      //partition
      pivot=begin;
      for(RandomIterator it=begin;it!=end;it++){
	 if(comp(*it,*(end-1))){
	    iter_swap(pivot,it);
	    pivot++;
	 }
      }
      // Move pivot to its final place
      iter_swap(pivot,end-1);
      
      if(k==pivot-begin)return pivot;
      // be careful here, e=end point +1, don't use pivot-1
      else if(k<pivot-begin) end=pivot;
      else {
	 k-=pivot-begin+1;
	 begin=pivot+1;
      }
   }
}

