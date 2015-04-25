/* 
   C(n,k) 
   Assumes factorial[n]=n!

   Time Complexity: O(1)
*/
LL C(LL n, LL k){
   return factorial[n]/(factorial[n-k]*factorial[k]);
}

/* 
   C(n,k,mod) (a.k.a C(n,k) MOD mod)

   Assumptions:
   factorial[n]=(n!)MOD mod
   gcd(n!,mod)=1 and mod is a prime (Euler's theorem)
   
   Requires: inv()
   Time Complexity: O(log(mod))
*/
LL C(LL n, LL k, LL mod){
    if(n<k)return 0;
    return factorial[n]*inv(factorial[n-k],mod)%mod*inv(factorial[k],mod)%mod;
}

/*
   C(n,k,mod) (a.k.a C(n,k) MOD mod)

   Assumptions:
   finv[n]=inv(factorial[n],mod) where factorial[n]=(n!)MOD mod
   finv[] can be calculated in O(n) see 'ModularInverse.cpp'
*/
LL C(LL n, LL k, LL mod){
    if(n<k)return 0;
    return factorial[n]*finv[n-k]%mod*finv[k]%mod;
}
