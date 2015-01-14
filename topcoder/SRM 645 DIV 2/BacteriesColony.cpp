#include <vector> 
using namespace std; 
class BacteriesColony{ 
public: 
vector <int> performTheExperiment(vector <int> v){ 
  while(true){ 
    vector<int> next; 
    next.push_back(v[0]); 
    for(int i=1;i<v.size()-1;i++){ 
      if(v[i-1]>v[i]&&v[i]<v[i+1]){ 
        next.push_back(v[i]+1); 
      } 
      else if(v[i-1]<v[i]&&v[i]>v[i+1]){ 
        next.push_back(v[i]-1); 
      } 
      else{ 
        next.push_back(v[i]); 
      } 
    } 
    next.push_back(v[v.size()-1]); 
    bool diff=false; 
    for(int i=0;i<v.size();i++){ 
      if(v[i]!=next[i]){ 
        diff=true; 
        break; 
      } 
    } 
    if(!diff){ 
      return next; 
    } 
    else{ 
      v=next; 
    } 
  } 
} 

};
