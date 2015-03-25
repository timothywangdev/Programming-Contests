#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[100];
int n;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int minimum=2147483647;
  int target=0;
  for(int i=1;i<n-1;i++){
    if(a[i+1]-a[i-1]<minimum){
      target=i;
      minimum=a[i+1]-a[i-1];
    }
  }
  for(int i=1;i<target;i++){
    minimum=max(minimum,a[i]-a[i-1]);
  }
  for(int i=target+2;i<n;i++){
    minimum=max(minimum,a[i]-a[i-1]);
  }
  cout<<minimum<<endl;
  return 0;
}
