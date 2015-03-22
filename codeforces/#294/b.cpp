#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int n;
LL a[3][100000];
map<LL,LL> m[3];
int main(){
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[0][i];
      map<LL,LL>::iterator it=m[0].find(a[0][i]);
      if(it==m[1].end()){
	 m[0][a[0][i]]=1;
      }
      else{
	 m[0][a[0][i]]=it->second+1;
      }
   }
   for(int i=0;i<n-1;i++){
      cin>>a[1][i];
      map<LL,LL>::iterator it=m[1].find(a[1][i]);
      if(it==m[1].end()){
	 m[1][a[1][i]]=1;
      }
      else{
	 m[1][a[1][i]]=it->second+1;
      }
   }
   for(int i=0;i<n-2;i++){
      cin>>a[2][i];
      map<LL,LL>::iterator it=m[2].find(a[2][i]);
      if(it==m[2].end()){
	 m[2][a[2][i]]=1;
      }
      else{
	 m[2][a[2][i]]=it->second+1;
      }
   }
   for(int i=0;i<n;i++){
      map<LL,LL>::iterator it=m[1].find(a[0][i]);
      if(it==m[1].end()){
	 cout<<a[0][i]<<endl;
      }
      else{
	 if(it->second==0){
	    cout<<a[0][i]<<endl;
	 }
	 else{
	    it->second--;
	 }
      }
   }
   for(int i=0;i<n-1;i++){
      map<LL,LL>::iterator it=m[2].find(a[1][i]);
      if(it==m[2].end()){
	 cout<<a[1][i]<<endl;
      }
      else{
	 if(it->second<=0){
	    cout<<a[1][i]<<endl;
	 }
	 else{
	    it->second--;
	 }
      }
   }
   return 0;
}
