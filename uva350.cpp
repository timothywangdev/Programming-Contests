#include <iostream>
#include <cstring>
using namespace std;

int Z,I,M,L;

bool used[10000];
int step[10000];
int counter=0;
int main(){
  while(cin>>Z>>I>>M>>L){
    if(!Z&&!I&&!M&&!L)break;
    counter++;
    cout<<"Case "<<counter<<": ";
    memset(used,false,sizeof(used));
    int s=0;
    while(true){
      if(used[L]){
	cout<<s-step[L]<<endl;
	break;
      }
      used[L]=true;
      step[L]=s;
      s++;
      L=(Z*L+I)%M;
    }
  }
  return 0;
}
