#include <iostream>

using namespace std;
typedef long long LL;

LL C[27],S[27];

LL N;
int main(){
  C[0]=1;
  S[1]=1;
  S[2]=1;
  for(int i=1;i<=26;i++){
    C[i]=(C[i-1]*(2*(2*i-1)))/(i+1);
    if(i>2){
      S[i]=3*(2*i-3)*S[i-1]-(i-3)*S[i-2];
      S[i]/=i;
    }
  }
  while(cin>>N){
    cout<<S[N]-C[N-1]<<endl;
  }
  return 0;
}
