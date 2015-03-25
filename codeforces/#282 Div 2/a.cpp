#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string.h>

using namespace std;

int digit[10][7]={
  {true,true,true,true,true,true,false},
  {false,true,true,false,false,false,false},
  {true,true,false,true,true,false,true},
  {true,true,true,true,false,false,true},
  {false,true,true,false,false,true,true},
  {true,false,true,true,false,true,true},
  {true,false,true,true,true,true,true},
  {true,true,true,false,false,false,false},
  {true,true,true,true,true,true,true},
  {true,true,true,true,false,true,true}
};
class Digit{
public:
  bool d[7];
  bool f[10];
  int rv;
  Digit(int n){
    memset(f,false,sizeof(f));
    for(int i=0;i<7;i++){
      d[i]=digit[n][i];
    }
  }
  void search(int i){
    if(i==7){
      bool found;
      for(int i=0;i<10;i++){
	found=true;
	for(int j=0;j<7;j++){
	  if(d[j]!=digit[i][j]){
	    found=false;
	    break;
	  }
	}
	if(found){
	  if(!f[i]){
	    rv++;
	    f[i]=true;
	  }
	  break;
	}
      }
      return;
    }
    if(!d[i]){
      d[i]=true;
      search(i+1);
      d[i]=false;
    }
    search(i+1);
  }
};

char c[2];
int main(){
  cin>>c[0]>>c[1];
  Digit d1(c[0]-'0'),d2(c[1]-'0');
  d1.rv=d2.rv=0;
  d1.search(0);
  d2.search(0);
  cout<< d1.rv*d2.rv<<endl;
  return 0;
}
