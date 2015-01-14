//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
#include <math.h>
#include "stdio.h"
//#define DEBUG
//using namespace std;
#ifdef DEBUG
ifstream fin("uva121.in");
ofstream fout("uva121.out");
#endif
float H,W,tmp1;
int fH,fW,sum,tmp,rv;
int main(){
	while(scanf("%f %f",&H,&W)==2){
        fH=H;
		fW=W;
		sum=fH*fW;
		rv=0;

        fH=(2/sqrt((float)3))*(H-1)+1;
		fW=W-0.5;
		if(fH*fW>sum){
           sum=fH*fW;
		   rv=1;
		}
		
		fW=W;
        tmp=fH/2*(2*fW-1)+(fH%2)*fW;
		if(tmp>sum){
           sum=tmp;
		   rv=1;
		}

		tmp1=H;
		H=W;
		W=tmp1;

		fH=(2/sqrt((float)3))*(H-1)+1;
		fW=W-0.5;
		if(fH*fW>sum){
           sum=fH*fW;
		   rv=1;
		}
		
		fW=W;
        tmp=fH/2*(2*fW-1)+(fH%2)*fW;
		if(tmp>sum){
           sum=tmp;
		   rv=1;
		}
		if(rv==0)
		    printf("%d grid\n",sum);
		else
            printf("%d skew\n",sum);
		//cout<<fixed<<setprecision(0)<<sum<<rv<<endl;
	}
}