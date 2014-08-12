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

vl flag,ending;
int N;
string s,t;
bool check(int len,SuffixArray &sa){
  if(!len){
    return true;
  }
  vl used=vl(N,false);
  int counter=0;
  for(LL i=0;i<=sa.n;i++){
    if(i<sa.n&&sa.LCP[i]>=len){
      if(!counter){
	if(!used[flag[sa.SA[i-1]]]&&sa.SA[i-1]+len-1<ending[flag[sa.SA[i-1]]]){
	  used[flag[sa.SA[i-1]]]=true;
	  counter++;
        }
      }
      if(!used[flag[sa.SA[i]]]&&sa.SA[i]+len-1<ending[flag[sa.SA[i]]]){
	used[flag[sa.SA[i]]]=true;
	counter++;
      }
    }
    else{
      if(counter>N/2){
	return true;
      }
      used.assign(N,false);
      counter=0;
    }
  }
  return false;
}
void print_rv(LL len,SuffixArray &sa){
  if(len==0){
    cout<<"?"<<endl;
    return;
  }
  vl used=vl(N,false);
  int counter=0;
  for(LL i=0;i<=sa.n;i++){
    if(i<sa.n&&sa.LCP[i]>=len){
      if(!counter){
	if(!used[flag[sa.SA[i-1]]]&&sa.SA[i-1]+len-1<ending[flag[sa.SA[i-1]]]){
	  used[flag[sa.SA[i-1]]]=true;
	  counter++;
        }
      }
      if(!used[flag[sa.SA[i]]]&&sa.SA[i]+len-1<ending[flag[sa.SA[i]]]){
	used[flag[sa.SA[i]]]=true;
	counter++;
      }
    }
    else{
      if(counter>N/2){
	string k=sa.T.substr(sa.SA[i-1],len);
	for(LL p=0;p<k.size();p++){
	  k[p]=k[p]-100+'a';
	}
	cout<<k<<endl;
      }
      used.assign(N,false);
      counter=0;
    }
  }
}
bool first=true;
int main(){
  while(cin>>N){
    if(!N)break;
    if(!first)cout<<endl;
    if(first)first=false;
    s="";
    char ending_char=0;
    for(int i=0;i<N;i++){
      cin>>t;
      for(int j=0;j<t.size();j++){
	t[j]=(t[j]-'a'+100);
      }
      s=s+t+ending_char;
      ending_char++;
    }
    flag=ending=vl(s.size(),0);
    int counter=0;
    for(int i=0;i<s.size();i++){
      flag[i]=counter;
      if(s[i]<100){
	ending[counter]=i;
	counter++;
      }
    }
    SuffixArray sa(s);
    sa.compute_LCP();
    
    /*
    for(int i=0;i<sa.n;i++){
      cout<<sa.SA[i]<<" "<<sa.LCP[i]<<" "<<sa.T.substr(sa.SA[i],sa.T.length()-sa.SA[i])<<endl;
    }
    */
    LL left=0,right=1000,middle;
    while(left<=right){
      middle=(left+right)/2;
      if(check(middle,sa)){
	left=middle+1;
      }
      else{
	right=middle-1;
      }
    }
    if(N==1){
      for(LL p=0;p<t.size();p++){
	  t[p]=t[p]-100+'a';
      }
      cout<<t<<endl;
      continue;
    }
    print_rv(left-1,sa);
  }
  return 0;
}
