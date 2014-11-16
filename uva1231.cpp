#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long LL;
int t,h,f,T,a,k;
int tree[2002][2002];
LL ff[2002][2002];
LL fm[2002];
int main(){
  cin>>T;
  for(int tt=0;tt<T;tt++){
    cin>>t>>h>>f;
    memset(tree,0,sizeof(tree));
    memset(ff,0,sizeof(ff));
    memset(fm,0,sizeof(fm));
    for(int i=0;i<t;i++){
      cin>>a;
      for(int j=0;j<a;j++){
	cin>>k;
	tree[k][i]++;
      }
    }
    LL maximum=0;
    for(int H=h;H>=0;H--){
      fm[H]=0;
      for(int i=0;i<t;i++){
	ff[H][i]=ff[H+1][i];
	if(H+f<=h){
	  ff[H][i]=max(ff[H][i],fm[H+f]);
	}
	ff[H][i]+=tree[H][i];
	fm[H]=max(fm[H],ff[H][i]);
      }
    }
    for(int i=0;i<t;i++){
      maximum=max(maximum,ff[0][i]);
    }
    cout<<maximum<<endl;
  }
  return 0;
}
