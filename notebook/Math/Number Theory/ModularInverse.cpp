/*
  Modular Multiplicative Inverse

  Computes n^(-1) MOD mod
*/


// Requires pow_mod_base2
// O(log(MOD))
LL inv(LL n,LL mod){
   assert(n!=0);
   return pow_mod_base2(n,mod-2,mod);
}

// Computing Inv(1..n) can be done in O(n) with a nice trick
LL inv[MAXN];
inv[1]=1%MOD;
for(int i=2;i<=n;i++){
   inv[i]=MOD-(inv[MOD%i]*(MOD/i))%MOD;;
}

// Computing inv(factorial[n],mod) in O(n)
LL finv[MAXN];
finv[0]=1;
finv[T] = inv(factorial[T],MOD);
for (int i = T - 1; i >= 1; i--) {
   // n! = (n+1)! / n
   // 1/(n!) = n * (1 / (n+1)! ) 
   finv[i] = ( (i + 1) * finv[i+1]) % MOD;
}
