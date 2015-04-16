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

int n,m,a[200001],b[400000],c[200001];
LL sum=0;
void Debug(){
   if(n==10&&m==399999&&a[1]==115&&a[2]==230&&a[3]==345&&a[4]==460&&a[5]==575){
      for(int i=1;i<=10;i++){
	 cout<<c[i]<<" ";
      }
      cout<<endl;
       }
}
void imBalanced(){
   if(c[1]&&!c[n]){
      for(int i=2;i<n;i++){
	 if(!c[i])break;
	 sum+=abs(a[i]-a[i-1]);
	 c[i]--;
      }
      for(int i=2;i<n;i++){
	 if(!c[i])break;
	 sum+=abs(a[i]-a[i-1]);
	 c[i]--;
      }
      return;
   }
   if(!c[1]&&c[n]){
      for(int i=n-1;i>1;i--){
	 if(!c[i])break;
	 sum+=abs(a[i]-a[i+1]);
	 c[i]--;
      }
      for(int i=n-1;i>1;i--){
	 if(!c[i])break;
	 sum+=abs(a[i]-a[i+1]);
	 c[i]--;
      }
      return;
   }
}
int main(){
   memset(c,0,sizeof(c));
   sum=0;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   cin>>m;
   F(i,m){
      cin>>b[i];
      c[b[i]]++;
   }
   //Debug();
   if(!c[1]&&!c[n]){
      F(i,m-1){
	 sum+=abs(a[b[i+1]]-a[b[i]]);
      }
      cout<<sum<<endl;
      return 0;
   }
   if(!(c[1]&&c[n])){
      imBalanced();
      cout<<sum<<endl;
      return 0;
   }
   int target=0;
   if(c[1]>c[n]){
      target=1;
   }
   else if(c[1]<c[n]){
      target=n;
   }
   int cur=(c[1]>=c[n])?1:n;
   int s=(c[1]>=c[n])?1:n;
   int last=0;
   while(c[1]||c[n]){
      c[cur]--;
      if(last){
	 sum+=abs(a[cur]-a[last]);
      }
      last=cur;
      if(s==1){
	 if(cur!=n){
	    cur++;
	 }
	 else{
	    s=n;
	    cur--;
	 }
      }
      else{
	 if(cur!=1){
	    cur--;
	 }
	 else{
	    s=1;
	    cur++;
	 }
      }
   }
   if(target){
      if(target==1){
	 for(int i=2;i<n;i++){
	    if(!c[i])break;
	    c[i]--;
	    sum+=abs(a[i]-a[i-1]);
	 }
	 for(int i=2;i<n;i++){
	    if(!c[i])break;
	    c[i]--;
	    sum+=abs(a[i]-a[i-1]);
	 }
      }
      else{
	 for(int i=n-1;i>1;i--){
	    if(!c[i])break;
	    c[i]--;
	    sum+=abs(a[i]-a[i+1]);
	 }
	 for(int i=n-1;i>1;i--){
	    if(!c[i])break;
	    c[i]--;
	    sum+=abs(a[i]-a[i+1]);
	 }
      }
      cout<<sum<<endl;
      return 0;
   }
   bool found_1=true;
   for(int i=2;i<n;i++){
      if(c[i]!=1){
	 found_1=false;
      }
   }
   if(!found_1){
      bool first=true;
      for(int i=2;i<n;i++){
	 if(!c[i])break;
	 if(!first&&c[i]==1){
	    break;
	 }
	 if(first&&c[i]>1){
	    first=false;
	 }
	 c[i]--;
	 sum+=abs(a[i]-a[i-1]);
      }
      for(int i=n-1;i>1;i--){
	 if(!c[i])break;
	 c[i]--;
	 sum+=abs(a[i]-a[i+1]);
      }
      cout<<sum<<endl;
   }
   else{
      // Here is the case we have ambiguity
      int last_length=0;
      for(int i=2;i<=n;i++){
	 if(!last_length){
	    last_length=abs(a[i]-a[i-1]);
	 }
	 else if(last_length!=abs(a[i]-a[i-1])){
	    cout<<"-1"<<endl;
	    return 0;
	 }
	 sum+=abs(a[i]-a[i-1]);
      }
      cout<<sum-last_length<<endl;
   }
   return 0;
}
