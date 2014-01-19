//#define DEBUG
//#include <fstream>
//#include <iostream>
#include <math.h>
#include <stdio.h>
//using namespace std;

#ifdef DEBUG
ifstream fin("uva111.in");
ofstream fout("uva111.out");
#endif

int correct[20],stu[20],map[20],f[21],J[21],N,maximum,tmp,rv,j,i;

int max(int a,int b){
	return (a>=b)?a:b;
}
int binarySearch(int ii,int jj,int target){
	if(ii>jj)
		return 0;
	int i=ii;
	int j=jj;
	#ifdef DEBUG
	fout<<"binary search: "<<j-i+1<<endl; 
    #endif
	int count=0;
	do{
	  count++;
      int middle=(i+j)/2;
	  if(middle+1>j&&stu[f[middle]]<target){
		  #ifdef DEBUG
		  fout<<"count: "<<count<<" expected: "<<log((float)(jj-ii+1))/log((float)2)<<endl;
		  #endif
		  return middle;
	  }
	  if(stu[f[middle]]<target&&target<=stu[f[middle+1]]){
		  #ifdef DEBUG
		  fout<<"count: "<<count<<" expected: "<<log((float)(jj-ii+1))/log((float)2)<<endl;
		  #endif
		  return middle;
	  }
      if(target<=stu[f[middle]])
		  j=middle-1;		  
	  if(stu[f[middle+1]]<=target)
		  i=middle+1;
	}while(i<=j);
	#ifdef DEBUG
	fout<<"count: "<<count<<" expected: "<<log((float)(jj-ii+1))/log((float)2)<<endl;
	#endif
	return 0;
}
int main(){
  #ifdef DEBUG
  fin>>N;
  for(int i=0;i<N;i++){
     fin>>tmp;
	 correct[tmp-1]=i+1;
  }
  for(int i=0;i<N;i++){
     map[correct[i]]=i;
  }
  while(fin){
  #else
  //cin>>N;
  scanf("%d",&N);
  for(i=0;i<N;i++){
     //cin>>tmp;
     scanf("%d",&tmp);
	 correct[tmp-1]=i+1;
  }
  for(i=0;i<N;i++){
     map[correct[i]]=i;
  }
  //while(cin){
  while(true){
  #endif
	  for(i=0;i<N;i++){
         #ifdef DEBUG
	     fin>>tmp;
		 #else
	     if(scanf("%d",&tmp)==EOF)
			 return 0;
	     //cin>>tmp;
		 #endif
		 stu[tmp-1]=i+1;
		 stu[tmp-1]=map[stu[tmp-1]];
		 f[i]=-1;
	  }
	  maximum=0;
	  for(i=0;i<N;i++){
	    if(i-1>=0&&stu[i-1]<stu[i])
          j=binarySearch(J[i-1],maximum,stu[i]);
		else
          j=binarySearch(1,maximum,stu[i]);
		J[i]=j;
		if(j==maximum||stu[i]<stu[f[j+1]]){
           f[j+1]=i;
		   maximum=max(maximum,j+1);
		}
	  }
	  #ifdef DEBUG
	  if(!fin.fail())
		  fout<<maximum<<endl;
	  #else
	   //if(!cin.fail())
	   //   cout<<maximum<<endl;
	  printf("%d\n",maximum);
	  #endif
  }
  return 0;
}