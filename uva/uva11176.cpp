

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
using namespace std;
typedef long long LL;

LL N;
double f[501][501],ff[501][501];
double p;

int main(){
 
  while(cin>>N>>p){
    if(!N)break;
    memset(f,0,sizeof(f));
    memset(ff,0,sizeof(ff));
    f[0][0]=1.0;
    for(int n=0;n<=N;n++){
      ff[0][n]=f[0][0];
    }
    for(int n=1;n<=N;n++){
      for(int s=0;s<=N;s++){
	ff[n][s]=ff[n-1][s];
	if(s==0){
	  ff[n][s]*=(1-p);
	  continue;
	}
	if(n-s-2>=0){
	  ff[n][s]-=ff[n-s-2][s]*(1-p)*pow(p,s+1);
	}
	else if(n==s+1){
	  ff[n][s]-=pow(p,s+1);
	}
      }
    }
    double expected=0.0;
    for(LL i=1;i<=N;i++){
      expected+=(ff[N][i]-ff[N][i-1])*i;
      //ycout<<ff[N][i]<<endl;
    }
    cout<<fixed<<setprecision(6)<<expected<<endl;
  }
  return 0;
}



/*
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
double dp[505][505];
int main() {
    int n;
    int i, j, k;
    double p;
    while(scanf("%d %lf", &n, &p) == 2 && n) {
        memset(dp, 0, sizeof(dp));
        for(i = 0; i <= n; i++)
            dp[0][i] = 1;
        for(i = 1; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                if(j == i-1)
                    dp[i][j] -= pow(p, j+1);
                else if(i-(j+1)-1 >= 0)
                    dp[i][j] -= dp[i-(j+1)-1][j]*(1-p)*pow(p, j+1);
            }
            dp[i][i] = 1;
        }
        double ret = 0;
        for(i = 1; i <= n; i++){
            ret += i*(dp[n][i]-dp[n][i-1]);
	    printf("%lf\n", dp[n][i]);
	}
        printf("%lf\n", ret);
    }
    return 0;
}
*/
