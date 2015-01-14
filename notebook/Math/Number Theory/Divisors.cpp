VL get_divisors(LL n){
  VL rv;
  LL m=sqrt(n);
  for(LL i=1;i<=m;i++){
     if(n%i==0){
	rv.push_back(i);
	if(n/i!=i){
	  rv.push_back(n/i);
	}
     }
  }
  return rv;
}

LL count_divisors(LL n){
  LL sum=0;
  LL m=sqrt(n);
  for(LL i=1;i<=m;i++){
    if(n%i==0){
      sum++;
      if(n/i!=i){
	sum++;
      }
    }
  }
  return sum;
}
