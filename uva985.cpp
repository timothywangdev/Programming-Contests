#include <iostream>
#include <string.h>
#include <string>
#include <queue>
#include <utility>
using namespace std;
typedef long long LL;

int mo[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
struct state{
  int r;
  int c;
  LL steps;
  int dir;
  state(){}
  state(int r,int c,LL steps,int dir):r(r),c(c),steps(steps),dir(dir){}
};
int R,C;

// N W S E
bool m[500][500][4];
LL rv[500][500][4];
LL answer;
string s;
int main(){

  while(cin>>R>>C){
    memset(m,false,sizeof(m));
    memset(rv,-1,sizeof(rv));
    answer=-1;
    for(int i=0;i<R;i++){
      int p=C;
      if(i==R-1)p--;
      for(int j=0;j<p;j++){
	cin>>s;
	for(int k=0;k<s.length();k++){
	  if(s[k]=='N'){
	    m[i][j][0]=true;
	  }
	  else if(s[k]=='E'){
	    m[i][j][3]=true;
	  }
	  else if(s[k]=='S'){
	    m[i][j][2]=true;
	  }
	  else{
	    m[i][j][1]=true;
	  }
	}
      }
    }
    queue<state> q;
    q.push(state(0,0,0,0));
    while(!q.empty()){
      state front=q.front();
      q.pop();
      if((rv[front.r][front.c][front.dir]>front.steps)||(rv[front.r][front.c][front.dir]==-1)){
	rv[front.r][front.c][front.dir]=front.steps;
	if(front.r==R-1&&front.c==C-1){
	  answer=front.steps;
	  break;
	}
      }
      else{
	continue;
      }
      for(int i=0;i<4;i++){
	if(m[front.r][front.c][(i+front.dir)%4]){
	  int rr=front.r+mo[i][0];
	  int cc=front.c+mo[i][1];
	  if(0<=rr&&rr<R&&0<=cc&&cc<C){
	    q.push(state(rr,cc,front.steps+1,(front.dir+1)%4));
	  }
	}
      }
    }
    if(answer==-1){
      cout<<"no path to exit"<<endl;
    }
    else{
      cout<<answer<<endl;
    }
  }
  return 0;
}
