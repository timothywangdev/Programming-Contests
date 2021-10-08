// Fisher Yates Shuffle
// Now, we have to prove that a number originally residing at index i will have \frac{1}{n} probability of ending up at index j. 
// We can see that this is the probability that i is not selected in the first n - j trials and is selected on the j^{th} trial. 
// This probability just becomes \frac{n- 1}{n} * \frac{n - 1}{n - 2} .... *\frac{j}{j + 1} * \frac{1}{j} = \frac{1}{n}. 
// Thus, our array is randomly shuffled and we are done.

vector<int> shuffle() {
      for(int i = rv.size()-1; i >= 0; i--) {
          int k = rand() % (i+1);
          swap(rv[i], rv[k]);
      }
      return rv;
}
