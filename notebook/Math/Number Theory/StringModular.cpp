// O(length(s))
// Computes s MOD mod
LL str_mod(string s,LL mod){
  LL rv=0;
  for(LL i=0;i<s.size();i++){
    rv=(rv*(10%mod)+(s[i]-'0')%mod)%mod;
  }
  return rv;
}
