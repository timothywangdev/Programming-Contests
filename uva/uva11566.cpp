#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double dp[1005][25];
int main() {
    int N, x, T, K;
    int i, j, k;
    while(scanf("%d %d %d %d", &N, &x, &T, &K) == 4 && N) {
        N++;
        int w[105];
        double p[105];
        for(i = 0; i < K; i++) {
            scanf("%d", &w[i]);
            p[i] = 0;
            double tmp;
            for(j = 0; j < N; j++) {
                scanf("%lf", &tmp);
                p[i] += tmp;
            }
        }
        int cost = N*x, dimSum = cost;
        while(cost < (dimSum+N*T)*11/10+(((dimSum+N*T)*11)%10 != 0))
            dimSum--;
        for(i = 0; i <= dimSum; i++)
            for(j = 0; j <= 2*N; j++)
                dp[i][j] = 0;
        dp[0][0] = 0;
        for(i = 0; i < K; i++) {
            for(j = dimSum; j >= w[i]; j--) {
                for(k = 1; k <= 2*N; k++) {
                    if(j-w[i] >= 0 && k-1 >= 0)
                        dp[j][k] = max(dp[j][k], dp[j-w[i]][k-1]+p[i]);
                    if(j-w[i]-w[i] >= 0 && k-2 >= 0)
                        dp[j][k] = max(dp[j][k], dp[j-w[i]-w[i]][k-2]+p[i]+p[i]);
                }
            }
        }
        double ret = 0;
        for(i = 0; i <= dimSum; i++)
            for(j = 0; j <= 2*N; j++)
                ret = max(ret, dp[i][j]);
        printf("%.2lf\n", ret/N);
    }
    return 0;
}
