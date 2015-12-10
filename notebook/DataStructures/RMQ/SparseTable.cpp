/*
  Static RMQ data structure
  Preprocessing: O(nlogn)
  Query: O(1)
*/

// Comparator
template <class T>
class Cmp{
public:
   bool operator()(const T &a, const T &b){
      return a<b;
   }
};

template <class T,class Cmp>
class SparseTable{
   vector<vector<T> > spt;
   vector<T> _data;
   Cmp cmp;
public:
   SparseTable(){}
   void build(vector<T> data){
      _data=data;
      int n=data.size();
      spt=vector<vector<T> >(n,vector<T>((int)log2((double)n)+1,0));
      for(int i=0;i<n;i++){
	 spt[i][0]=i;
      }
      for(int j=1;(1<<j)<=n;j++){
	 for(int i=0;i+(1<<j)-1<n;i++){
	    if(cmp(_data[spt[i][j-1]],_data[spt[i+(1<<(j-1))][j-1]]))
	       spt[i][j]=spt[i][j-1];
	    else
	       spt[i][j]=spt[i+(1<<(j-1))][j-1];
	 }
      }
   }
   // Returns an index of the 'minimum' element
   int query(int i,int j){
      int k=(int)floor(log((double)j-i+1)/log(2.0));
      if(!cmp(_data[spt[j-(1<<k)+1][k]],_data[spt[i][k]])){
	 return spt[i][k];
      }
      else{
	 return spt[j-(1<<k)+1][k];
      }
   }
};
