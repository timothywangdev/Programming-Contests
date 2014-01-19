#include <iostream>
#include <string.h>
using namespace std;
int m,n;
int up[101],dl[101],dr[101];
unsigned long long rvUp,rvDL,rvDR;
unsigned long long power(unsigned long long n,unsigned long long k){
     unsigned long long rv=1;
	 for(unsigned long long i=0;i<k;i++)
		 rv*=n;
	 return rv;
}
int main(){
	while(cin>>n>>m){
		rvUp=rvDL=rvDR=1;
        if(n==0&&m==0)
			break;
        memset(up,0,sizeof(up));
		memset(dl,0,sizeof(dl));
		memset(dr,0,sizeof(dr));
        for(int i=1;i<=n;i++)
			up[i]++;
		for(int i=1;i<=n-m;i++){
			if(up[i])
				up[i]--;
			else
                dl[i]++;
		}
		for(int i=1;i<=m;i++){
			if(up[i])
				up[i]--;
			else
                dr[i]++;
		}
		for(int i=1;i<n;i++){
			if(up[i]>0){
			   bool changed=false;
			   for(int j=1;j<=n-m;j++){
				   if(up[i]>0&&dl[j]>0&&i%j==0){
					   dl[j]--;
					   up[i]=0;
					   up[i/j]++;
					   changed=true;
				   }
			   }
			   if(changed)
				   i=0;
			}
		}
		for(int i=1;i<n;i++){
			if(up[i]>0){
			   bool changed=false;
			   for(int j=1;j<=m;j++){
				   if(up[i]>0&&dr[j]>0&&i%j==0){
					   dr[j]--;
					   up[i]=0;
					   up[i/j]++;
					   changed=true;
				   }
			   }
			   if(changed)
				   i=0;
			}
		}
        for(int i=1;i<=n-m;i++){
			if(dl[i]>0){
				rvDL=rvDL*power(i,dl[i]);
			}
		}
		for(int i=1;i<=m;i++){
			if(dr[i]){
				rvDR=rvDR*power(i,dr[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(up[i]){
				rvUp=rvUp*power(i,up[i]);
			}
		}
		unsigned long long rv=rvUp/(rvDL*rvDR);
        cout<<n<<" things taken "<<m<<" at a time is "<<rv<<" exactly."<<endl;
	}
	return 0;
}