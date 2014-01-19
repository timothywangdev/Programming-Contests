//#define DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#ifdef DEBUG
ifstream fin("uva122.in");
ofstream fout("uva122.out");
#endif

struct node{
	int v;
	string p;
};

node t[256];
string tmp;
char ignore;
int value,N;
bool comp(const node &a,const node &b){
	int la=a.p.length(),lb=b.p.length();
	if(la<lb)
		return true;
	else if(la==lb){
		if(a.p<b.p)
			return true;
		else
			return false;
	}
	return false;
}
bool check(){
	node tmp;
	if(t[0].p!="")
		return false;
	for(int i=0;i<N;i++)
		if(i!=0){
		   if(t[i].p==t[i-1].p)
			   return false;
		   tmp.p=t[i].p.substr(0,t[i].p.length()-1);
		   tmp.v=-1;
		   if(!binary_search(t,t+i,tmp,comp))
			   return false;
		}
    return true;
}
int main(){
#ifdef DEBUG
	while(fin>>ignore){
#else
	while(cin>>ignore){
#endif
		if(ignore!='(')
			break;
		N=0;
		while(true){

			#ifdef DEBUG
			ignore=fin.peek();
			if(ignore==')'){
				fin>>ignore;
				break;
			}
			fin>>value>>ignore>>tmp>>ignore;
			#else
			ignore=cin.peek();
			if(ignore==')'){
				cin>>ignore;
				break;
			}
			cin>>value>>ignore>>tmp>>ignore;
			#endif

			tmp.erase(tmp.length()-1,1);
			t[N].v=value;
			t[N].p=tmp;
			N++;
		}
		if(N>=1){
		sort(t,t+N,comp);
		#ifdef DEBUG
		if(!check())
			fout<<"not complete"<<endl;
		else{
			for(int i=0;i<N-1;i++)
				fout<<t[i].v<<" ";
			fout<<t[N-1].v<<endl;
		}
		#else
		if(!check())
			cout<<"not complete"<<endl;
		else{
			for(int i=0;i<N-1;i++)
				cout<<t[i].v<<" ";
			cout<<t[N-1].v<<endl;
		}
		#endif
		}
	}
	return 0;
}