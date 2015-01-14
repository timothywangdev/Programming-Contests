#include <iostream>
#include <iomanip>
using namespace std;

int nco,nca,nsh;
int main(){
  while(cin>>nco>>nca>>nsh){
    int n=nco+nca;
    cout<<fixed<<setprecision(5)<<(((double)nco/(double)(n))*((double)nca/(double)(n-nsh-1)))+(((double)nca/(double)(n))*((double)(nca-1)/(double)(n-nsh-1)))<<endl;
  }
  return 0;
}
