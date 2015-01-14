#include <vector> 
#include <utility> 
#include <algorithm> 
using namespace std; 
typedef long long LL; 
class ConnectingCars{ 
  public: 
  LL cal(int pos,vector<pair<LL,LL> > &v){ 
    LL sum=0; 
    LL target=v[pos].first+v[pos].second; 
    for(int i=pos+1;i<v.size();i++){ 
      sum+=v[i].first-target; 
      target+=v[i].second; 
    } 
    target=v[pos].first; 
    for(int i=pos-1;i>=0;i--){ 
      sum+=target-(v[i].first+v[i].second); 
      target-=v[i].second; 
    } 
    return sum; 
  } 
  long long minimizeCost(vector <int> positions, vector <int> lengths){ 
    vector<pair<LL,LL> > v; 
    for(int i=0;i<positions.size();i++){ 
      v.push_back(make_pair(positions[i],lengths[i])); 
    } 
    sort(v.begin(),v.end()); 
    LL minimum=-1; 
    for(int i=0;i<v.size();i++){ 
      if(minimum==-1){ 
        minimum=cal(i,v); 
      } 
      else{ 
        minimum=min(minimum,cal(i,v)); 
      } 
    } 
    return minimum; 
  } 

};
