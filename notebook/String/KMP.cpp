/*
  Find all occurrences of a substring P in T
  O(n+m)

  Warning: Using array to speed up!!!
 */
char P[MAXN],T[MAXN];
int next[MAXN];

void KMP_preprocess(char P[],int m,int next[]){
  int i=0,j=-1;
  next[0]=-1;
  while(i<m){
    while(j>=0&&P[i]!=P[j])j=next[j];
    i++;j++;
    next[i]=j;
  }
}
void KMP(char T[],char P[],int next[],int n,int m,int start=0){
  int i=start,j=0;
  KMP_preprocess(P,m,next);
  while(i<n){
    while(j>=0&&T[i]!=P[j])j=next[j];
    i++;j++;
    if(j==m){
      cout<<"i-j"<<endl;
      j=next[j];
    }
  }
}
