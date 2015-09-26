static LL poly_pow[2][100000]; // Change this according to the _pow[2][max_len(str)]
static const LL MOD[2]={1000000009,1000000021};
static const LL P[2]={113,129};//{113,129}; // larger primes {229,233}

class PolyHash{
public:
  LL v[2];
  int len;
  
  PolyHash():len(0),v{0,0}{}
  PolyHash(LL val):len(1),v{val,val}{}
  PolyHash(const PolyHash &other):len(other.len),v{other.v[0],other.v[1]}{}
  PolyHash operator>>(int k){
    // TODO
  }
  PolyHash operator<<(int k){
    PolyHash rv(*this);
    rv.len+=k;
    rv.v[0]=(v[0]*poly_pow[0][k])%MOD[0];
    rv.v[1]=(v[1]*poly_pow[1][k])%MOD[1];
    return rv;
  }
  // Append
  PolyHash operator+(const PolyHash& other) const{
    PolyHash rv(*this);
    rv=rv<<other.len;
    rv.v[0]=(other.v[0]+rv.v[0])%MOD[0];
    rv.v[1]=(other.v[1]+rv.v[1])%MOD[1];
    return rv;
  }
  bool operator==(const PolyHash& other) const{
    // if(n==20){
    //cout<<len<<" "<<v[0]<<" "<<v[1]<<endl
    // cout<<other.len<<" "<<other.v[0]<<" "<<other.v[1]<<endl;
    // }
    return (len==other.len&&v[0]==other.v[0]&&v[1]==other.v[1]);
  }
  

};
