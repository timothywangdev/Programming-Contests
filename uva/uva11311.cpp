#include <iostream>

using namespace std;
int t,m,n,r,c;
int main(){
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>m>>n>>r>>c;
    if(r^c^(m-r-1)^(n-c-1)){
      cout<<"Gretel"<<endl;
    }
    else{
      cout<<"Hansel"<<endl;
    }
  }
  return 0;
}
