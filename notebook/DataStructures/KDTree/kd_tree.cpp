
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;

template <class T>
struct KDNode{
  vector<T> *point;
  struct KDNode<T> *left, *right;
};

template <class T>
class KDTree{
  struct KDNode<T> *root;
  // using points to speed up swapping in partition() and save memory
  vector<vector<T>* > points;
  int dim;

  int partition(int s, int e, int pivot, int cur_dim){
    swap(points[s],points[pivot]);
    int head=s+1,tail=e;
    while(head<=tail){
      while(head<=tail&&points[head]->at(cur_dim)<=points[s]->at(cur_dim))head++;
      while(head<=tail&&points[tail]->at(cur_dim)>points[s]->at(cur_dim))tail--;
      if(head<=tail){
	swap(points[head],points[tail]);
	head++;
	tail--;
      }
    }
    swap(points[s],points[tail]);
    return tail;
  }

  int _medianOfMedians(int s,int e, int k, int cur_dim){
    auto cmp = [cur_dim](vector<T> *a, vector<T> *b)->bool{
      return a->at(cur_dim)<b->at(cur_dim);
    };
    if(e-s+1 <= 5){
      sort(points.begin()+s, points.begin()+e+1,cmp);
      return s+k-1;
    }

    for(int left=s;left<=e;left+=5){
      int right = left+4<=e?left+4:e;
      swap(points[_medianOfMedians(left,right,(right-left+1)/2+1,cur_dim)],points[s+(left-s)/5]);
    }

    int pivot =  _medianOfMedians(s, s+(e-s)/5,((e-s)/5+1)/2+1, cur_dim);
    pivot = partition(s,e,pivot,cur_dim);
    if(pivot-s+1==k){
      return pivot;
    }
    else if(k<pivot-s+1){
      return _medianOfMedians(s,pivot-1,k,cur_dim);
    }
    else{
      return _medianOfMedians(pivot+1,e,k-(pivot-s+1), cur_dim);
    }
  }

  struct KDNode<T>* _build(int s, int e, int cur_dim){
    if(s>e)return NULL;
    struct KDNode<T> *node = new KDNode<T>();
    int pivot = _medianOfMedians(s, e, (e-s+1)/2+1, cur_dim);
    pivot = partition(s,e,pivot,cur_dim);
    node->point = points[pivot];
    node->left = _build(s,pivot-1,(cur_dim+1)%dim);
    node->right = _build(pivot+1,e,(cur_dim+1)%dim);
    return node;
  }
  double distSqr(vector<T> *a, vector<T> *b){
    double rv=0.0;
    for(int i=0;i<dim;i++){
      rv+=(b->at(i)-a->at(i))*(b->at(i)-a->at(i));
    }
    return rv;
  }
  void _KNN(vector<T> *p, int k, struct KDNode<T>* node, int cur_dim, multimap<double,vector<T>*> &bpq){
    if(!node)return;
    
    /* Add the current point to the BPQ. Note that this is a no-op if the
     * point is not as good as the points we've seen so far.
     */
    bpq.insert(make_pair(distSqr(node->point, p),node->point));
    if(bpq.size()>k){
      typename multimap<double,vector<T>*>::iterator it = bpq.end();
      it--;
      bpq.erase(it);
    }

    /* Recursively search the half of the tree that contains the test point. */
    if(p->at(cur_dim)<=node->point->at(cur_dim)){
      _KNN(p,k,node->left,(cur_dim+1)%dim,bpq);
    }
    else{
      _KNN(p,k,node->right,(cur_dim+1)%dim,bpq);
    }

    /* If the candidate hypersphere crosses this splitting plane, look on the
     * other side of the plane by examining the other subtree.
     */
    if(bpq.size()<k||abs(node->point->at(cur_dim)-p->at(cur_dim))<bpq.rbegin()->first){
      if(p->at(cur_dim)<=node->point->at(cur_dim)){
	_KNN(p,k,node->right,(cur_dim+1)%dim,bpq);
      }
      else{
	_KNN(p,k,node->left,(cur_dim+1)%dim,bpq);
      }
    }
  }

  // reports the entire subtree rooted at [node]
  void _rangeSearch_reportSubTree(struct KDNode<T>* node, vector<pair<T,T> > range, vector<vector<int>* > &rv){
    if(!node)return;
    bool dataInRange=true;
    for(int i=0;i<dim;i++){
      if(!(range[i].first<=node->point->at(i)&&node->point->at(i)<=range[i].second)){
	dataInRange=false;
      }
    }
    if(dataInRange){
      rv.push_back(node->point);
    }
    _rangeSearch_reportSubTree(node->left, range, rv);
    _rangeSearch_reportSubTree(node->right, range, rv);
  }

  void _rangeSearch(struct KDNode<T>* node, int cur_dim, vector<pair<T,T> > &qrange, vector<pair<T,T> > bb, 
		    vector<vector<int>* > &rv){
    if(!node)return;
    bool qrangeInsideBB=true;
    bool qrangeOverlapBB=false;
    bool dataInQrange=true;
    for(int i=0;i<dim;i++){
      if(!(bb[i].first<=qrange[i].first&&bb[i].second<=qrange[i].second)){
	qrangeInsideBB=false;
      }
      if(!(qrange[i].second<bb[i].first||qrange[i].first>bb[i].second)){
	qrangeOverlapBB=true;
      }
      if(!(qrange[i].first<=node->point->at(i)&&node->point->at(i)<=qrange[i].second)){
	dataInQrange=false;
      }
    }
    if(!qrangeOverlapBB)return;
    if(qrangeInsideBB){
      _rangeSearch_reportSubTree(node,qrange,rv);
      return;
    }
    if(dataInQrange){
      rv.push_back(node->point);
    }
    pair<T,T> old_bb = bb[cur_dim];
    bb[cur_dim].second=node->point->at(cur_dim);
    _rangeSearch(node->left, (cur_dim+1)%dim, qrange, bb, rv);
    bb[cur_dim] = old_bb;
    bb[cur_dim].first=node->point->at(cur_dim);
    _rangeSearch(node->right, (cur_dim+1)%dim, qrange, bb, rv);
  } 
   
public:
  KDTree(){
    this->root = NULL;
  }
  /*
    Time  O(k*nlogn)
    Space O(kn)
   */
  void build(vector<vector<T>* > &points){
    this->points = points;
    this->dim = points.size()?points[0]->size():0;
    root=_build(0,points.size()-1,0);
  }
  /*
    Average O(logn)
    Worst   O(n)
   */
  void insert(vector<T>* point){
    struct KDNode<T> *cur = root;
    int cur_dim = 0;
    while(cur){
      if(point->at(cur_dim)<=cur->point->at(cur_dim)){
	cur = cur->left;
      }
      else{
	cur = cur->right;
      }
    }
    cur = new KDNode<int>();
    cur->point=point;
  }
  /*
    O(logn)
    Friedman derives that the search time is logarithmic in file size. 
    He also states that the number of records that is examined for the k nearest neighbours 
    according to the ∞-distance in the ideal case is O((r^(1/k)+1)^k
   */
  vector<pair<double, vector<int>*> > KNN(vector<T> *p, int k){
    
    // Bounded Priority Queue (a.k.a priority queue with fixed size)
    multimap<double,vector<T>*> bpq;
    //vector<vector<T>*> rv;
    vector<pair<double, vector<int>*> > rv;
    _KNN(p,k,root,0,bpq);
    for(typename multimap<double,vector<T>*>::iterator it = bpq.begin();it!=bpq.end();it++){
      rv.push_back(*it);
    }
    return rv;
  }
  
  /* 
     k=1 O(r+logn)                optimal
     k>=2 dim O(r+n^(1-1/d))      sub-optimal
     Note that Lower bounds: omega(r+klogn)
     where r is the number of points in the query region
  */
  vector<vector<int>* > rangeSearch(vector<pair<T,T> > qrange){
    vector<vector<int>* > rv;
    // bounding box, starts with -inf to +inf for each dim
    vector<pair<T,T> > bb;
    for(int i=0;i<dim;i++){
      bb.push_back(make_pair(numeric_limits<T>::min(),numeric_limits<T>::max()));
    }
    _rangeSearch(root,0,qrange,bb,rv);
    return rv;
  }

};


double distSqr(vector<int> a, vector<int> b){
    double rv=0.0;
    for(int i=0;i<a.size();i++){
      rv+=(b.at(i)-a.at(i))*(b.at(i)-a.at(i));
    }
    return rv;
 }

int main(){
  /*
  for(int i=0;i<10;i++){
    vector<int> v={3,6,4,1,7,5,8,2,9,10};
    cout<<v[medianOfMedians(v,0,v.size()-1,i+1)]<<endl;
  }
  */
  vector<vector<int> > v= {{1,3},{4,2},{5,5},{1,4},{2,6},{7,1},{3,4},{4,5}};
  vector<vector<int>* > points;
  for(int i=0; i<v.size();i++){
    points.push_back(&v[i]);
  }
  KDTree<int> kd;
  kd.build(points);
  vector<pair<int,int>> range;
  range.push_back(make_pair(1,3));
  range.push_back(make_pair(2,4));
  vector<vector<int>* > rv = kd.rangeSearch(range);
  for(auto i:rv){
    cout<<i->at(0)<<" "<<i->at(1)<<endl;
  }
  /*
  for(int i=0;i<v.size();i++){
    kd.insert(&v[i]);
  }
  
  vector<int> test = {3,8};
  vector<pair<double, vector<int>> > correct;
  for(int i=0;i<v.size();i++){
    correct.push_back(make_pair(distSqr(test,v[i]),v[i]));
  }
  sort(correct.begin(),correct.end(),[](pair<double, vector<int>> a, 
					pair<double, vector<int>> b)->bool{
	 return a.first<b.first;
       });
  for(int i=0;i<5;i++){
    cout<<correct[i].first<<" "<<correct[i].second.at(0)<<" "<<correct[i].second.at(1)<<endl;
  }
  cout<<"================================"<<endl;
  vector<pair<double, vector<int> *> > ps = kd.KNN(&test, 5);
  for(auto i:ps){
     cout<<i.first<<" "<<i.second->at(0)<<" "<<i.second->at(1)<<endl;
  }
  */

  return 0;
}
