/*
  Sieve of Eratosthenes
  Find primes<=upperbound
  O(NloglogN)

  usage:
  find primes<=N
  sieve(N)
*/

bitset<10000010> bs;
void sieve(LL upperbound){
  int _sieve_size=upperbound;
  bs.set();
  bs[0]=bs[1]=0;
  for(LL i=2;i*i<=_sieve_size;i++){
    if(bs[i]){
      for(LL j=i*i;j<=_sieve_size;j+=i){
         bs[j]=0;
      }
      primes.push_back(i);
    }
  }
}
