#include <iostream>
#include <string>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
string s;
string state;

char shape[2]={'x','o'};
bool check(int id,string &state,int i,int j){
  return (state[0]==shape[id]&&state[5]==shape[id]&&state[10]==shape[id]&&state[15]==shape[id])||
    (state[3]==shape[id]&&state[6]==shape[id]&&state[9]==shape[id]&&state[12]==shape[id])||
    (state[i*4]==shape[id]&&state[i*4+1]==shape[id]&&state[i*4+2]==shape[id]&&state[i*4+3]==shape[id])||
    (state[j]==shape[id]&&state[4+j]==shape[id]&&state[8+j]==shape[id]&&state[12+j]==shape[id]);
}
ii play(int id,string state){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      int k=i*4+j;
      if(state[k]=='.'){
	string next=state;
	next[k]=shape[id];
	if(check(id,next,i,j)){
	  return make_pair(i,j);
	}
	ii rv=play(1-id,next);
	if(rv.first==-1){
	  return make_pair(i,j);
	}
      }
    }
  }
  return make_pair(-1,-1);
}
int main(){
  while(cin>>s){
    if(s[0]=='$')break;
    state="";
    for(int i=0;i<4;i++){
      cin>>s;
      state=state+s;
    }
    ii rv=play(0,state);
    if(rv.first!=-1){
      cout<<"("<<rv.first<<","<<rv.second<<")"<<endl;
    }
    else{
      cout<<"#####"<<endl;
    }
  }
  return 0;
}
