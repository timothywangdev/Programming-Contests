#include <iostream>
#include <string>
#include "string.h"
#include "stdlib.h"
using namespace std;

int main(){
	int n,tmp;
	bool exist[3001];
	while(cin>>n){
		bool first=true;
		int last,d;
		memset(exist,false,sizeof(exist));
		for(int i=0;i<n;i++){
			cin>>tmp;
			if(!first){
				d=abs(tmp-last);
				last=tmp;
				if(d<=3000)
					exist[d]=true;
			}
			else{
				first=false;
			}	last=tmp;
		}
		bool jolly=true;
		for(int i=1;i<n;i++){
			if(!exist[i]){
				jolly=false;
				break;
			}
		}
		if(jolly)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
return 0;
}