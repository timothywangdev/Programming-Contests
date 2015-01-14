//y#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;
int N;
int r[14];
int two_power[14]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
int done;
int count;
char ch;
void search(int co,int ld,int rd,int k){
  if(k==N){
    count++;
    return;
  }
  int pos=done & (~(co|ld|rd|r[k]));
  while(pos){
    int p=pos & -pos;
    pos-=p;
    search(co|p, (ld|p)<<1, (rd|p)>>1,k+1);
  }
}
int T=0;
int main(){
  while(scanf("%d",&N)){
    T++;
    if(!N)break;
    for(int i=0;i<N;i++){
      r[i]=0;
      for(int j=0;j<N;j++){
	scanf("%c",&ch);
	if(ch=='*'){
	  r[i]+=two_power[j];
	}
	if(ch=='\n')j--;
      }
    }
    count=0;
    done=(1<<N)-1;
    search(0,0,0,0);
    printf("Case %d: %d\n",T,count);
    //cout<<"Case "<<T<<": "<<count<<endl;
  }
  
  return 0;
}
