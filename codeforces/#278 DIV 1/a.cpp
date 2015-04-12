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

int hp_y,atk_y,def_y,hp_m,atk_m,def_m,h,a,d,max_hp,max_atk,max_def;
bool check(int hp,int atk,int def){
   int km=0,ky=0;
   if(max(0,atk-def_m)==0){
      km=-1;
   }
   if(max(0,atk_m-def)==0){
      ky=-1;
   }
   if(km==-1&&ky==-1)return false;
   if(km==-1&&ky!=-1)return false;
   if(km!=-1&&ky==-1)return true;
   km=(hp_m%max(0,atk-def_m)==0)?hp_m/max(0,atk-def_m):hp_m/max(0,atk-def_m)+1;
   ky=(hp%max(0,atk_m-def)==0)?hp/max(0,atk_m-def):hp/max(0,atk_m-def)+1;
   return km<ky;
}
int main(){
   cin>>hp_y>>atk_y>>def_y>>hp_m>>atk_m>>def_m>>h>>a>>d;

   max_atk=max(hp_m+def_m,atk_y);
   max_def=max(atk_m,def_y);
   int rv=-1;
   for(int j=atk_y;j<=max_atk;j++){
      for(int k=def_y;k<=max_def;k++){
	 if(j<=def_m)continue;
	 int kv,km,i;
	 if(k>=atk_m){
	    i=hp_y;
	 }
	 else{
	    km=(hp_m%(j-def_m)==0)?hp_m/(j-def_m):hp_m/(j-def_m)+1;
	    i=max(hp_y,km*(atk_m-k)+1);
	 }
	 if(check(i,j,k)){
	    if(rv==-1){
	       rv=(i-hp_y)*h+(j-atk_y)*a+(k-def_y)*d;
	    }
	    else{
	       rv=min(rv,(i-hp_y)*h+(j-atk_y)*a+(k-def_y)*d);
	    }
	  }
      }
   }
   cout<<rv<<endl;
   return 0;
}
