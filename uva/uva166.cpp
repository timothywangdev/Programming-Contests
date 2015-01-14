//#include <iostream>
//#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <string>
//#include <iomanip>
#include <string.h>
#define MAXIMUM 20560
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva166.in");
ofstream fout("uva166.out");
#endif
int coin[6],n,maximum;
short value[6]={5,10,20,50,100,200};
short remain[6];
short minimum;
short q[810];
/*
short p(short v,short sum,short toAdd){
    if(v==0){
		if(sum+q[toAdd]<minimum)
			minimum=sum+q[toAdd];
		return 0;
	}
	if(sum+q[toAdd]+1>=minimum){
		return MAXIMUM;
	}
	short minV=MAXIMUM;
	for(short i=5;i>=0;i--)
		if(remain[i]>0&&v-value[i]>=0){
			remain[i]--;
			minV=min(minV,p(v-value[i],sum+1,toAdd));
			remain[i]++;
		}
	return minV+1;
}
*/
short p(short v,short sum,short toAdd){

	for(int i=5;i>=0;i--)
		if(v>=value[i]){
			int num=v/value[i];
			if(num<=coin[i]){
			   sum+=num;
			   v-=(v/value[i])*value[i];
			}
			else{
			   sum+=coin[i];
			    v-=coin[i]*value[i];
			}
		}
	if(v==0)
	 return sum;
	else
	 return MAXIMUM;
}
short getq(int v){
	short sum=0;
	for(int i=5;i>=0;i--)
		if(v>=value[i]){
			sum+=v/value[i];
			v-=(v/value[i])*value[i];
		}
	return sum;
}
void process(){
	/*
	if(n%5!=0){
		cout<<MAXIMUM<<endl;
		return;
	}
	
	memset(q,80,sizeof(q));
	q[0]=0;
	for(short i=5;i<=maximum-n;i+=5)
		for(short j=0;j<6;j++)
			if(i-value[j]>=0)
				q[i]=min(q[i],(short)(q[i-value[j]]+1));
	short sum=0;
	for(short i=0;i<6;i++){
		remain[i]=coin[i];
		sum+=remain[i];
	}
	*/
	
	minimum=p(n,0,0);
	
	for(short i=n+5;i<=maximum;i+=5)
		{
			short rv=p(i,0,i-n)+q[i-n];
			if(rv<minimum){
				minimum=rv;
			}
		}
#ifdef DEBUG
	fout<<setw(3)<<minimum<<endl;
#else
	printf("%3d\n",minimum);
#endif
									
}
int main(){
	int s1,s2;
	char ch;
	for(int i=0;i<=800;i+=5)
		q[i]=getq(i);
	#ifdef DEBUG
	while(fin>>coin[0]>>coin[1]>>coin[2]>>coin[3]>>coin[4]>>coin[5]){
	#else
	while(true){
	#endif
		scanf("%d %d %d %d %d %d",&coin[0],&coin[1],&coin[2],&coin[3],&coin[4],&coin[5]);
		if(coin[0]==0&&coin[1]==0&&coin[2]==0&&coin[3]==0&&coin[4]==0&&coin[5]==0)
			break;
		#ifdef DEBUG
		fin>>s1>>ch>>s2;
		#else
		scanf("%d.%d",&s1,&s2);
		#endif
		n=s1*100+s2;
		maximum=coin[0]*5+coin[1]*10+coin[2]*20+coin[3]*50+coin[4]*100+coin[5]*200;
		if(maximum>800)
			maximum=800;
		process();
	}

	return 0;
}