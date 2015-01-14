#include <iostream>
#include <string.h>
#include <string>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10616.in");
ofstream fout("uva10616.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int N,Q,D,M;
long long n[201],f[201][11][20];
int counter=0;
int main(){
	redirect();
	while(cin>>N>>Q){
	   if(N==0&&Q==0)
		   break;
	   counter++;
	   cout<<"SET "<<counter<<":"<<endl;
	   for(int i=0;i<N;i++)
		   cin>>n[i];
	   for(int i=0;i<Q;i++){
		   cin>>D>>M;
		   memset(f,0,sizeof(f));
		   f[0][0][0]=1;
		   for(int j=1;j<=N;j++)
			  for(int k=0;k<D;k++)
			   for(int m=0;m<=M&&m<=j;m++){
				   if(m>0){
					   int t;
					   if(n[j-1]<0){
						   t=n[j-1]%D;
						   t+=D;
					   }
					   else{
						   t=n[j-1]%D;
					   }
					   if(0<=k-t&&k-t<=D-1)
					    f[j][m][k]+=f[j-1][m-1][k-t];
					   if(0<=D+k-t&&D+k-t<=D-1)
					    f[j][m][k]+=f[j-1][m-1][D+k-t];
				   }
				   f[j][m][k]+=f[j-1][m][k];
			   }
		  cout<<"QUERY "<<i+1<<": ";
		  cout<<f[N][M][0]<<endl;
	   }
	}
return 0;
}