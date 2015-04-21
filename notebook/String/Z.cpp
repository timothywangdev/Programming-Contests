
// Z[i]:length of longest substring starting from P[i] which is also a prefix of P
void Z_alg(char P[],int m,int Z[]){
   int L = 0, R = 0;
   for (int i = 1; i < m; i++) {
      if (i > R) {
	 L = R = i;
	 while (R <m && P[R-L] == P[R]) R++;
	 Z[i] = R-L; R--;
      } else {
	 int k = i-L;
	 if (Z[k] < R-i+1) Z[i] = Z[k];
	 else {
	    L = i;
	    while (R < m && P[R-L] == P[R]) R++;
	    Z[i] = R-L; R--;
	 }
      }
   }
}
