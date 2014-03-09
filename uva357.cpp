#include <iostream>
#include <string>
#include <string.h>
using namespace std;
long long f[30001][5],v[5]={1,5,10,25,50};
long long process(int n){
	memset(f,0,sizeof(f));
	for(int j=0;j<5;j++)
		f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<5;j++)
			for(int k=0;k<=j;k++)
				if(i-v[j]>=0)
				   f[i][j]+=f[i-v[j]][k];
    long long sum=0;
	for(int j=0;j<5;j++)
		sum+=f[n][j];
	return sum;
}
int main(){
	int tmp;
	while(cin>>tmp){
        long long rv=process(tmp);
		if(rv==1)
			cout<<"There is only 1 way to produce "<<tmp<<" cents change."<<endl;
		else
			cout<<"There are "<<rv<<" ways to produce "<<tmp<<" cents change."<<endl; 
	}
	return 0;
}