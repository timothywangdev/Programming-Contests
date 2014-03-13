//#include <iostream>
#include <stdio.h>
using namespace std;
/*
#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10920.in");
ofstream fout("uva10920.out");
#endif

void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
*/
//long long v[500002];
long long v(long long i){
	if(i<=1){
		return i;
	}
	long long j=2*i-3;
	return j*j+1;
}
/*
void hehe(){
	v[0]=0;
	v[1]=1;
	for(int i=2;i<=500001;i++){
		long long j=2*i-1;
		j-=2;
		v[i]=j*j+1;
	}
}
*/

long long S,N,t;
int binarySearch(long long maxLevel){
    long long  minL=1,maxL=maxLevel,middle;

	while(true){
		middle=(minL+maxL)/2;
		if(v(middle)<=N)
			minL=middle+1;
		else
			maxL=middle-1;
		if(minL>=maxL){
			if(N>=v(minL))
				return minL;
			else
				return minL-1;
		}

	}
}
void getRelativeCorordinate(long long level,long long &r,long long &c){
	long long l=2*level-1;

	long long last=v(level)-1,minimum,maximum,targetDir,targetStart;
	for(int i=0;i<4;i++){
		minimum=last+1;
		maximum=minimum+l-2;
		last=maximum;
		if(minimum<=N&&N<=maximum){
			targetDir=i;
			targetStart=minimum;
			break;
		}
	}
	long long offset=N-targetStart;
	if(targetDir==0){
		r=l;c=l-1-offset;
	}
	else if(targetDir==1){
		r=l-1-offset;c=1;
	}
	else if(targetDir==2){
		r=1;c=2+offset;
	}
	else{
		r=2+offset;c=l;
	}
	int shift=(S-l)/2;
	c+=shift;
	r+=shift;
}
int main(){
	//redirect();
	//hehe();
	long long r,c;
	while(scanf("%d %d",&S,&N)){
		if(!S&&!N)
			break;
		if(N==1){
			r=(S+1)/2;
			c=(S+1)/2;
		}else{
			t=binarySearch((S+1)/2);
			getRelativeCorordinate(t,r,c);
		}
		printf("Line = %d, column = %d.\n",r,c);
	}
	return 0;
}