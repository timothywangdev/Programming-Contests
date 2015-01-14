#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef vector<LL> vl;

class SuffixArray{
public:
  // the input string, up to 100K chars
  string T;
  // the length of T
  LL n;
  // rank array
  vl RA, tmpRA;
  // suffix array
  vl SA, tmpSA;
  // for counting sort;
  vl c;
  // Longest Common Prefix
  vl LCP;

  // Usage: SuffixArray(str+'$')
  SuffixArray(string T):T(T),n(T.length()){
    RA=tmpRA=SA=tmpSA=c=vl(n,0);
    construct_SA();
  }
  void counting_sort(LL k){
    LL i,sum,maxi=max((LL)300,n);
    c.assign(maxi,0);
    for(LL i=0;i<n;i++){
      c[i+k<n?RA[i+k]:0]++;
    }
    for(LL i=sum=0;i<maxi;i++){
      LL t=c[i];
      c[i]=sum;
      sum+=t;
    }
    for(LL i=0;i<n;i++){
      tmpSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
    }
    for(LL i=0;i<n;i++){
      SA[i]=tmpSA[i];
    }
  }
  void construct_SA(){
    LL i,k,r;
    for(i=0;i<n;i++){
      RA[i]=T[i];
      SA[i]=i;
    }
    for(k=1;k<n;k<<=1){
      counting_sort(k);
      counting_sort(0);
      tmpRA[SA[0]]=r=0;
      for(i=1;i<n;i++){
	tmpRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]])&&(RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
      }
      for(i=0;i<n;i++){
	RA[i]=tmpRA[i];
      }
      if(RA[SA[n-1]]==n-1)break;
    }
  }
  // String processing functions
  // Computes Longest Common Prefix in O(n)
  void compute_LCP(){
    LL i,L;
    vl phi=vl(n,0),plcp=vl(n,0);
    LCP=vl(n,0);
    phi[SA[0]]=-1;
    for(i=1;i<n;i++){
      phi[SA[i]]=SA[i-1];
    }
    for(i=L=0;i<n;i++){
      if(phi[i]==-1){
	plcp[i]=0;
	continue;
      }
      while(T[i+L]==T[phi[i]+L]){L++;}
      plcp[i]=L;
      L=max(L-1,(LL)0);
    }
    for(i=0;i<n;i++){
      LCP[i]=plcp[SA[i]];
    }
  }

  // Computes Longest Common Substring in O(n)
  // Returns a vector of LCS in lex order
  vector<string> compute_LCS(LL len_1,LL len_2){
    LL maximum=0;
    vector<string> rv;
    for(LL i=1;i<n;i++){
      if((SA[i]<len_1&&SA[i-1]>=len_1)||(SA[i]>=len_1&&SA[i-1]<len_1)){
	if(maximum<LCP[i]){
	  maximum=LCP[i];
	  rv.clear();
	  rv.push_back(T.substr(SA[i],maximum));
	}
	else if(maximum==LCP[i]&&maximum!=0){
	  if(rv[rv.size()-1]!=T.substr(SA[i],maximum)){
	    rv.push_back(T.substr(SA[i],maximum));
	  }
	}
      }
    }
    return rv;
  }
};

string s1,s2,t;
bool first=true;
int main(){
  while(getline(cin,s1)&&getline(cin,s2)){
    if(!first)cout<<endl;
    if(first){
      first=false;
    }
     SuffixArray sa(s1+'$'+s2+'#');
     //ySuffixArray sa("GATAGACA$CATA#");
    sa.compute_LCP();
    vector<string> rv=sa.compute_LCS(s1.length(),s2.length());
    for(int i=0;i<rv.size();i++){
      cout<<rv[i]<<endl;
    }
    if(rv.size()==0){
      cout<<"No common sequence."<<endl;
    }
    if(!getline(cin,t)){
      break;
    }
  }
  return 0;
}
