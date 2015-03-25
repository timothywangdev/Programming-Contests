#include <bits/stdc++.h>

using namespace std;

int n,xx,yy,x,y;
vector<pair<int,int> > points;
bool used[1000];
bool check(int i,int j){
  if(points[i].first==0){
    return (points[j].first==0);
  }
  if(points[i].second==0){
    return (points[j].second==0);
  }
  //turn fabs(((double)points[i].second/(double)points[i].first)-((double)points[j].second/(double)points[j].first)<1e-9);
  return points[i].first*points[j].second==points[i].second*points[j].first;
}
int main(){
  cin>>n>>xx>>yy;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    x-=xx;
    y-=yy;
    points.push_back(make_pair(x,y));
  }
  memset(used,false,sizeof(used));
  int sum=0;
  for(int i=0;i<n;i++){
    if(!used[i]){
      used[i]=true;
      sum++;
      for(int j=0;j<n;j++){
	if(!used[j]&&check(i,j)){
	  //ut<<i<<" "<<j<<endl;
	  used[j]=true;
	}
      }
    }
  }
  cout<<sum<<endl;
  return 0;
}
