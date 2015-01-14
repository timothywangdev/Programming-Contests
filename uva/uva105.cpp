//#define DEBUG
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#ifdef DEBUG
ifstream fin("uva105.in");
ofstream fout("uva105.out");
#endif


class building{
public:
	int l;
	int h;
	int r;
	building(int L,int H,int R):l(L),h(H),r(R){}
};



vector<building*> bs;
int L,H,R;
building* tmp;

bool heightCmp(building *b1,building *b2){
	return b1->h>b2->h;
}

bool leftCmp(building *b1,building *b2){
	return b1->l<b2->l;
}

void deleteBuild(int i){
	delete bs[i];
    for(int k=i;k<(int)bs.size()-1;k++)
		bs[k]=bs[k+1];
	bs.pop_back();
}
void addBuild(int l,int h,int r,int pos){
	building *tmp=new building(l,h,r);
	/*
	for(vector<building*>::reverse_iterator rit=bs.rbegin();rit!=bs.rend();rit++)
		if((*rit)->h>=h){
			vector<building*>::iterator it=rit.base();
			--it;
			bs.insert(it,tmp);
		}
	*/
			bs.insert(bs.begin()+pos+1,tmp);
}
int process(int i,int j){
	int rv=-2;
	if(bs[j]->l<bs[i]->r&&bs[j]->l>=bs[i]->l){
		if(bs[j]->r>bs[i]->r)
			bs[j]->l=bs[i]->r;
		else{
			deleteBuild(j);
			rv=-1;
		}
	}else if(bs[j]->r>bs[i]->l&&bs[j]->r<=bs[i]->r){
		if(bs[j]->l<bs[i]->l)
			bs[j]->r=bs[i]->l;
		else{
			deleteBuild(j);
			rv=-1;
		}
	}
	else if(bs[j]->l<bs[i]->l&&bs[j]->r>bs[i]->r){
            addBuild(bs[i]->r,bs[j]->h,bs[j]->r,j);
			bs[j]->r=bs[i]->l;
			rv=j;
	}
	return rv;
}
int main(){
	int rv;
#ifdef DEBUG
	while(fin>>L>>H>>R){
#else
	while(cin>>L>>H>>R){
#endif
		if(L!=R){
		 tmp=new building(L,H,R);
		 bs.push_back(tmp);
		}
	}
	sort(bs.begin(),bs.end(),heightCmp);
	for(int i=0;i<(int)bs.size();i++)
		for(int j=i+1;j<(int)bs.size();j++){
		   rv=process(i,j);
		   if(rv==-1)
			   j--;
		}
	sort(bs.begin(),bs.end(),leftCmp);

	int lastH=-1,lastR=bs[0]->l;
	if(bs[0]->l>1)
		cout<<"1 0 ";
	for(int i=0;i<(int)bs.size();i++)
		if(bs[i]->l>lastR){
			cout<<lastR<<" 0 "<<bs[i]->l<<" "<<bs[i]->h<<" ";
			lastR=bs[i]->r;
			lastH=bs[i]->h;
		}
		else if(bs[i]->h==lastH){
			lastR=bs[i]->r;
		}
		else{
			cout<<bs[i]->l<<" "<<bs[i]->h<<" ";
			lastR=bs[i]->r;
			lastH=bs[i]->h;
		}
	cout<<bs[(int)bs.size()-1]->r<<" 0"<<endl;
}