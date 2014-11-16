#include <iostream>
#include <string.h>
#include <utility>
#include <queue>
using namespace std;
typedef long long LL;
bool visited[65536];
LL count[65536];
int mo[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int ind[65536];
int T,R,C,N,x,y,mx,my,xx,yy;

bool getBit(int pos, int &n){
  return (n&(1<<pos))>0;
}
void clearBit(int pos,int &n){
  n&=~(1<<pos);
}
void setBit(int pos,int &n){
  n|=(1<<pos);
}

void dp(int state){
  int pos=state,nextState,mx,my,xx,yy,x,y,idx,p,tmp;
  p=pos&(-pos);
  if(pos-p==0){
    count[state]=1;
    return;
  }
  if(visited[state]){
    return;
  }
  visited[state]=true;
  count[state]=0;
  while(pos){
    p=pos&(-pos);
    pos-=p;
    idx=ind[p];
    x=idx/C;
    y=idx-x*C;
    for(int i=0;i<8;i++){
      mx=x+mo[i][0];
      my=y+mo[i][1];
      xx=x+2*mo[i][0];
      yy=y+2*mo[i][1];
      if(0<=xx&&xx<R&&0<=yy&&yy<C){
	if(getBit(mx*C+my,state)&&!getBit(xx*C+yy,state)){
	  nextState=state;
	  clearBit(x*C+y,nextState);
	  clearBit(mx*C+my,nextState);
	  setBit(xx*C+yy,nextState);
	  dp(nextState);
	  count[state]+=count[nextState];
	}
      }
    }
  }
}
int main(){
  N=1;
  ind[1]=0;
  for(int i=1;i<=15;i++){
    N*=2;
    ind[N]=i;
  }
  cin>>T;
  for(int t=0;t<T;t++){
    memset(visited,false,sizeof(visited));
    cin>>R>>C>>N;
    int state=0;
    for(int i=0;i<N;i++){
      cin>>x>>y;
      x--;
      y--;
      state+=1<<(x*C+y);
    }
    dp(state);
    cout<<"Case "<<t+1<<": "<<count[state]<<endl;
  }
  return 0;
}
