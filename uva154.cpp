#include <iostream>
#include <fstream>
#include <string>
#define MAXIMUM 2147483647
using namespace std;
#ifdef DEBUG
ifstream fin("uva154.in");
ofstream fout("uva154.out");
#endif
const int bin[5]={0,4,8,12,16};
const int garbage[5]={2,6,10,14,18};
struct City{
	char r;
	char o;
	char y;
	char g;
	char b;
};

City city[100];
int N;
string s;
void decode(string s){
	for(int i=0;i<5;i++)
		switch(s[bin[i]])
	{
		case 'r':city[N].r=s[garbage[i]];
			break;
		case 'o':city[N].o=s[garbage[i]];
			break;
		case 'y':city[N].y=s[garbage[i]];
			break;
		case 'g':city[N].g=s[garbage[i]];
			break;
		case 'b':city[N].b=s[garbage[i]];
			break;
	}
	N++;
}
int getChanges(int i,int j){
    int changes=0;
	if(city[i].b!=city[j].b)
		changes++;
	if(city[i].g!=city[j].g)
		changes++;
	if(city[i].o!=city[j].o)
		changes++;
    if(city[i].r!=city[j].r)
		changes++;
	if(city[i].y!=city[j].y)
		changes++;
	return changes;
}
void process(){
	int minCity=-1,minChanges=MAXIMUM;
	for(int i=0;i<N;i++){
		int totalChanges=0;
		for(int j=0;j<N;j++)
			totalChanges+=getChanges(i,j);
		if(totalChanges<minChanges){
			minChanges=totalChanges;
			minCity=i;
		}
	}
	cout<<minCity+1<<endl;
}
int main(){
	N=0;
	while(cin>>s){
		if(s[0]=='#')
			break;
		if(s[0]=='e'){
			process();
			N=0;
		}
		else{
		  decode(s);
		}
	}
	return 0;
}