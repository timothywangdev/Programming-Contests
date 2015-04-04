#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;

class Cut{
   list<int>::iterator a[200001];
   list<int> l;
   bool pos[200001];
   int cur_max=0;
public:
   Cut(VI v,int M){
      memset(pos,false,sizeof(pos));
      pos[0]=pos[M]=true;
      F(i,v.size()){
	 pos[v[i]]=true;
      }
      F(i,200001){
	 if(pos[i]){
	    list<int>::iterator pre=l.end();
	    if(l.size()>=1){
	       pre--;
	       cur_max=max(cur_max,i-*pre);
	    }
	    l.push_back(i);
	    a[i]=l.end();
	    a[i]--;
	 }
      }
   }
   int getMax(int i){
      int rv=cur_max;
      list<int>::iterator it=a[i];
      list<int>::iterator right=a[i],left=a[i];
      right++;
      left--;
      cur_max=max(cur_max,*right-*left);
      l.erase(it);
      return rv;
   }
   int getMax(){
      return cur_max;
   }
};
int w,h,n,k;
vector<pair<char,int> > input;
char c;
int main(){
   cin>>w>>h>>n;
   VI H,V;
   F(i,n){
      cin>>c>>k;
      input.pb(mp(c,k));
      if(c=='H'){
	 H.pb(k);
      }
      else{
	 V.pb(k);
      }
   }
   Cut HC=Cut(H,h);
   Cut VC=Cut(V,w);
   VL rv;
   FR(i,input.size()){
      int mh,mv;
      if(input[i].first=='H'){
	 mh=HC.getMax(input[i].second);
	 mv=VC.getMax();
      }
      else{
	 mh=HC.getMax();
	 mv=VC.getMax(input[i].second);
      }
      rv.pb((LL)mh*(LL)mv);
   }
   FR(i,rv.size()){
      cout<<rv[i]<<endl;
   }
   return 0;
}
