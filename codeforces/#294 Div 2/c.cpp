#include <bits/stdc++.h>

using namespace std;

int n,m;
int main(){
   cin>>n>>m;
   int maximum=0;
   for(int t=0;t<=n;t++){
      int a=n-t;;
      int b=m-2*t;
      maximum=max(maximum,t+min(a/2,b));
   }
   cout<<maximum<<endl;
   return 0;
}
