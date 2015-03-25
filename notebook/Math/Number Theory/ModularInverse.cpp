/*
  Modular Multiplicative Inverse

  Computes n^(-1) MOD mod
*/


// Requires pow_mod_base2
// O(log(MOD))
LL Inv(LL n){
   assert(n!=0);
   return pow_mod_base2(n,MOD-2,MOD);
}

// Computing Inv(1..n) can be done in O(n) with a nice trick
LL inv[MAXN];
inv[1]=1%MOD;
for(int i=2;i<=n;i++){
   inv[i]=MOD-(inv[MOD%i]*(MOD/i))%MOD;;
}
