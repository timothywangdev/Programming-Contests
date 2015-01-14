#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int N,C,P;
int getPermu(int a,int b,int c){
	if(a==b&&b==c)
		return 1;
	if(a==b||a==c||b==c)
		return 3;
	return 6;
}
int main(){
	v.push_back(0);
	for(int i=1;i<=20;i++){
		for(int j=1;j<=3;j++){
			vector<int>::iterator it=find(v.begin(),v.end(),i*j);
			if(it==v.end())
				v.push_back(i*j);
		}
	}
	vector<int>::iterator it=find(v.begin(),v.end(),50);
	if(it==v.end())
		v.push_back(50);
	while(cin>>N){
		if(N<=0)
			break;
		C=P=0;
		for(int a=0;a<v.size();a++)
			for(int b=a;b<v.size();b++)
				for(int c=b;c<v.size();c++){
					if(v[a]+v[b]+v[c]==N){
						C++;
						P+=getPermu(v[a],v[b],v[c]);
					}
				}
		if(C==0){
          cout<<"THE SCORE OF "<<N<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
		}
		else{
		  cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<N<<" IS "<<C<<"."<<endl;
		  cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<N<<" IS "<<P<<"."<<endl;
		}
		cout<<"**********************************************************************"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}