#include <iostream>
#include <algorithm>
using namespace std;

int cor[4][2];
int main(){

  int xll_1,yll_1,xur_1,yur_1,xll_2,yll_2,xur_2,yur_2;
  int N;
  cin>>N;
  for(int t=0;t<N;t++){
    if(t>0)cout<<endl;
    cin>>xll_1>>yll_1>>xur_1>>yur_1>>xll_2>>yll_2>>xur_2>>yur_2;
    int upper=min(yur_1,yur_2);
    int lower=max(yll_1,yll_2);
    int left=max(xll_1,xll_2);
    int right=min(xur_1,xur_2);
    if(upper>lower&&left<right){
      cout<<left<<" "<<lower<<" "<<right<<" "<<upper<<endl;
    }
    else{
      cout<<"No Overlap"<<endl;
    }
  }
  return 0;
}
