#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string.h>
#include <bitset>
using namespace std;
typedef long long LL;


int ten_pow[10];
int v[8];
int sign[9];
int n;
int counter=0;
int f(int &n,int pos){
  return n-((n/ten_pow[pos+1])*ten_pow[pos+1]);
}
int d(int &n,int pos){
  return (f(n,pos)-f(n,pos-1))/ten_pow[pos];
}
int dance(int &n,int i,int j){
  if(i>j){
    return f(n,7)-f(n,i)+(f(n,i-1)-f(n,j-1))*10+(f(n,i)-f(n,i-1))/ten_pow[i-j]+f(n,j-1);
  }
  else{
    return f(n,7)-f(n,j)+(f(n,i)-f(n,i-1))*ten_pow[j-i]+(f(n,j)-f(n,i))/10+f(n,i-1);
  }
}
int sorted=12345678,answer,ne;
bitset<87654322> exist;
bitset<17> bs;

void sieve(LL upperbound){
  LL _sieve_size=upperbound+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(LL i=2;i<=_sieve_size;i++){
    if(bs[i]){
      for(LL j=i*i;j<=_sieve_size;j+=i){
         bs[j]=0;
      }
    }
  }
}

int main(){
  sieve(16);
  ten_pow[0]=1;
  for(int i=1;i<10;i++){
    ten_pow[i]=10*ten_pow[i-1];
  }
  while(cin>>v[0]){
    if(!v[0])break;
    counter++;
    exist.reset();
    answer=-1;
    for(int i=1;i<8;i++){
      cin>>v[i];
    }
    for(int i=0;i<8;i++){
      sign[(int)abs(v[i])]=(v[i]<0)?-1:1;
    }
    n=0;
    for(int i=0;i<8;i++){
      n+=abs(v[i])*ten_pow[8-i-1];
    }
    queue<pair<int,LL> > q;
    q.push(make_pair(n,0));
    while(!q.empty()){
      pair<int,LL> p=q.front();
      n=p.first;
      q.pop();
      if(!exist[n]){
	if(n==sorted){
	  answer=p.second;
	  break;
	}
	exist[n]=1;
	for(int i=0;i<8;i++){
	  for(int j=0;j<8;j++){
	    if(i!=j){
	      int ii=d(n,i);
	      int jj=d(n,j);
	      if(bs[ii+jj]==0)continue;
	      ii*=sign[ii];
	      jj*=sign[jj];
	      if(ii*jj>=0)continue;
	      if(i>j){
		// left
		ne=dance(n,i,j+1);
		q.push(make_pair(ne,p.second+1));
		// right
		ne=dance(n,i,j);
		q.push(make_pair(ne,p.second+1));
	      }
	      else{
		// left
		ne=dance(n,i,j-1);
		q.push(make_pair(ne,p.second+1));
		// right
		ne=dance(n,i,j);
		q.push(make_pair(ne,p.second+1));
	      }
	    }
	  }
	}
      }
    }
    cout<<"Case "<<counter<<": "<<answer<<endl;
  }
  return 0;
}
