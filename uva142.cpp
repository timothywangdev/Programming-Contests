//#define DEBUG
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#define MAXIMUM 2147483647
using namespace std;
#ifdef DEBUG
ifstream fin("uva142.in");
ofstream fout("uva142.out");
#endif
struct P{
	int x;
	int y;
};
struct Region{
	P tl;
	P br;
	int index;
};
struct Icon{
	P p;
	int index;
};


vector<Icon> I;
vector<Region> R;
vector<int> icons;
vector<P> M;
char ch;
Icon tmp;
Region tmpR;
P t;
bool inRange(int target,int minimum,int maximum){
	return (minimum<=target)&&(target<=maximum);
}
bool inRegion(Icon &icon,Region &region){
	return inRange(icon.p.x,region.tl.x,region.br.x)&&
		   inRange(icon.p.y,region.tl.y,region.br.y);
}
void deleteOverlappedIcons(){
	for(unsigned int j=0;j<R.size();j++){
	   for(unsigned int i=0;i<I.size();i++)
			if(inRegion(I[i],R[j])){
			   I.erase(I.begin()+i);
			   i--;
			}
	}
}
int findRegion(int x,int y){
	for(int i=(int)R.size()-1;i>=0;i--){
		Icon tmp2;
		tmp2.p.x=x;
		tmp2.p.y=y;
		if(inRegion(tmp2,R[i]))
			return i;
	}
	return -1;	
}
int dist(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void findIcon(int x,int y){
	int minDist=MAXIMUM;
	for(unsigned int i=0;i<I.size();i++)
		if(dist(x,y,I[i].p.x,I[i].p.y)<minDist){
			minDist=dist(x,y,I[i].p.x,I[i].p.y);
			icons.clear();
			icons.push_back(I[i].index);
		}
		else if(dist(x,y,I[i].p.x,I[i].p.y)==minDist)
			icons.push_back(I[i].index);
}
void displayRegion(int i){
#ifdef DEBUG
	fout<<(char)('A'+i)<<endl;
#else
	cout<<setw(0)<<(char)('A'+i)<<endl;
#endif
}
void displayIcon(){
	#ifdef DEBUG
	for(unsigned int i=0;i<icons.size();i++)
		fout<<setw(3)<<icons[i]+1;
	fout<<endl;
	#else
	for(unsigned int i=0;i<icons.size();i++)
		cout<<setw(3)<<icons[i]+1;
	cout<<endl;
	#endif
}
void process(int x,int y){
	int rv=findRegion(x,y);
	if(rv>=0){
		displayRegion(rv);
	}
	else{
		icons.clear();
		findIcon(x,y);
		displayIcon();
	}
}
int main(){
	I.clear();
		R.clear();
		M.clear();
		icons.clear();
	#ifdef DEBUG
	while(fin>>ch){
		if(ch=='I'){
			fin>>tmp.p.x>>tmp.p.y;
    #else
	while(cin>>ch){
		if(ch=='I'){
			cin>>tmp.p.x>>tmp.p.y;
    #endif
			tmp.index=I.size();
			I.push_back(tmp);
		}
		else if(ch=='R'){
			#ifdef DEBUG
			fin>>tmpR.tl.x>>tmpR.tl.y>>tmpR.br.x>>tmpR.br.y;
			#else
			cin>>tmpR.tl.x>>tmpR.tl.y>>tmpR.br.x>>tmpR.br.y;
			#endif
			tmpR.index=R.size();
			R.push_back(tmpR);
		}
		else if(ch=='M'){

	    #ifdef DEBUG
		fin>>t.x>>t.y;
	    #else
		cin>>t.x>>t.y;
	    #endif
		M.push_back(t);
		}
		else if(ch=='#')
		  break;
	}
	deleteOverlappedIcons();
	for(unsigned int i=0;i<M.size();i++)
		process(M[i].x,M[i].y);

	return 0;
}