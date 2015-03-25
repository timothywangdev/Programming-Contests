/*
  Modular Exponentiation

  Computes (base^exp)MOD mod
*/

// O(log2(N))
LL pow_mod_base2(LL base, LL exp, LL mod){
  LL rv=1;
  base=base%mod;
  while(exp>0){
    if(exp&1){
      rv=(rv*base)%mod;
    }
    exp>>=1;
    base=(base*base)%mod;
  }
  return rv;
}

// O(log10(N))
// Useful when 'exp' is a big number
LL pow_mod_base10(LL base,string exp,LL mod){
  LL rv=1;
  base=base%mod;
  for(LL i=exp.length()-1;i>=0;i--){
    rv=(rv*pow_mod_base2(base,(int)(exp[i]-'0'),mod))%mod;
    base=pow_mod_base2(base,10,mod);
  }
  return rv;
}
