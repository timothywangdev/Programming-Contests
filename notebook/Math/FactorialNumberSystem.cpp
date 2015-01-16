/*
  fac vector index: 0 1 2 3 ...
  factorial number: 0!1!2!3!...
 */

// O(nlogn)
vector<int> fac_to_permu(vector<int> &fac){
  int n=fac.size();
  SegmentTree<int,int> st;
  vector<int> data(n,1);
  st.build_tree(data);
  vector<int> permu(n,0);
  for(int i=0;i<n;i++){
    permu[i]=st.find_idx(fac[n-i-1]+1);
    st.update(permu[i],0);
  }
  return permu;
}
// O(nlogn)
vector<int> permu_to_fac(vector<int> &permu){
  int n=permu.size();
  SegmentTree<int,int> st;
  vector<int> fac(n,0),data(n,0);
  st.build_tree(data);
  for(int i=n-1;i>=0;i--){
    fac[n-i-1]=st.query(0,permu[i]);
    st.update(permu[i],1);
  }
  return fac;
}
