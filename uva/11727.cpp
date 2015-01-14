#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> ve;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
	  int a,b,c;
	  cin>>a>>b>>c;
	  ve.push_back(a);
	  ve.push_back(b);
	  ve.push_back(c);
	  sort(ve.begin(),ve.end());
	  cout<<"Case "<<i+1<<": "<<ve[1]<<endl;
	  ve.clear();
  }
  return 0;
}
