#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define STRICTLY_INCREASNG

vector<int> LIS(vector<int> v){
  /* 	
	O(nlogk) where k is the length of LIS
	========================================
   	L[i].first represents the smallest ending value of all length-i LIS found so far
  	L[i].second represents the corresponding index of that smallest ending value
  	========================================
   	L[i] is always ordered on L[i].first (a.k.a L[i-1].first<=L[i].first) 
	as the second last element of any LIS of length i is smaller(strictly increasing) [or equal(for non-increasing)]
   	than its last element. Thus we can do binary seach on L[i].first.
	
        Proof(consider strictly increasing):

        Suppose L[i-1].first>=L[i].first, then we can always use the second last element of LIS at L[i] to make L[i-1].first
	smaller, which contradicts the fact L[i-1].first is the smallest ending value of all length-i LIS found so far.
	========================================
	Algorithm(consider strictly increasing):
	We binary search L to determine the longest possible subsequence we can create by appending the current element v[i]--
	simply find L[i] such that L[i].first<v[i]. Let the index of such element be j.

	Case 1:
	If v[i] is larger(or equal) than all elements in L, we can append v[i] to the largest LIS to get a larger one

	Case 2:
	otherwise, we can always update L[j+1].first = v[i], L[j+1].second=i to make L[j+1].first smaller or equal.
	Proof:
	Suppose the original L[j+1].first<v[i], the the binary search wound've found j+1 instead of j, a contradiction.
	
	Note this is a greedy strategy. By storing the LIS with smaller ending value, we maximize our ability to further extend
	the LIS with future values.
  */
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

