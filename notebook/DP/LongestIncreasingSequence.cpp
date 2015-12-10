#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define STRICTLY_INCREASNG

vector<int> LIS(vector<int> v){
  // L[i]->first represents the smallest ending value of all length-i LIS found so far
  // L[i]->second represents the corresponding index of that smallest ending value
  
  // L[i-1].first<=L[i].first as the second last element of any LIS of length i is smaller
  // than its last element. 
  // (the smallest ending value of LIS of length i-1 < the smallest ending value of LIS of length i) 

  vector<int> parent(v.size(),-1);
  vector<pair<int,int> > L;
  for(int i=0;i<v.size();i++){
    #ifdef STRICTLY_INCREASNG
    // set item->second to 0 to find the first ending value that is larger or equal to v[i] in L
    // we are actually dealing with it-1 (L[k] < v[i])
    pair<int,int> item=make_pair(v[i],0);
    vector<pair<int,int> >::iterator it=lower_bound(L.begin(),L.end(),item);
    // set the index to i
    item.second=i;
    #else
    // set item->second to i since the maximum number of elements in L is i(we haven't added v[i] yet)
    // and then we find the first ending value that is larger than v[i]
    // we are actually dealing with it-1 (L[k]<=v[i])
    pair<int,int> item=make_pair(v[i],i);
    vector<pair<int,int> >::iterator it=upper_bound(L.begin(),L.end(),item);
    #endif
    // v[i] is larger(or equal) than all elements in L, we can append v[i] to the largest LIS
    // to get a larger one
    if(it==L.end()){
      parent[i]=!L.size()?-1:L.back().second;
      L.push_back(item);
    }
    else{
      // Otherwise, we use greedy strategy to use a (possible)smaller ending value for LIS ends at 
      // it->second(we know that v[i] is at least as good as it->first)
      
      // By storing the LIS with smaller ending value, we maximize our ability to further extend the LIS
      // with future values
      parent[i]=it->second;
      *it=item;
    }
  }
  // The length of LIS is the size of L
  vector<int> rv;
  for(int i=L.back().second;i!=-1;i=parent[i]){
    rv.push_back(v[i]);
  }
  reverse(rv.begin(),rv.end());
  return rv;
}

