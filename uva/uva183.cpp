#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
//#decine DEBUG
#ifdef DEBUG
ifstream cin("uva183.in");
ofstream cout("uva183.out");
#endif
string s;
string ch;
int r,c,counter;
bool result[300][300];
struct Part{
	int p[4][2];
};
Part getPart(int r,int c){
	Part rv;
	int h,v;
	if(r%2==0)
		h=r/2+1;
	else
		h=r/2+2;
	if(c%2==0)
		v=c/2+1;
	else
		v=c/2+2;
	rv.p[0][0]=rv.p[1][0]=h-1;
	rv.p[2][0]=rv.p[3][0]=r-h+1;

	rv.p[0][1]=rv.p[2][1]=v-1;
	rv.p[1][1]=rv.p[3][1]=c-v+1;
	if(r==1){
		rv.p[2][0]=rv.p[3][0]=-1;
	}
	if(c==1){
		rv.p[1][0]=rv.p[3][0]=-1;
	}
	return rv;
}
void output(int r,int c,int sr,int sc,char first){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			result[i+sr][j+sc]=(bool)(first-'0');
}
void checkNewLine(){
	counter++;
	if(counter==50){
		cout<<endl;
		counter=0;
	}
}
int toB(int r,int c,int sr,int sc,int start){
	char first;
	cin>>first;
	if(!(first=='0'||first=='1'||first=='D'))
		cin>>first;
	if(first!='D'){
		output(r,c,sr,sc,first);
		return start;
	}
	start++;
	int end;
	Part p=getPart(r,c);
	end=toB(p.p[0][0],p.p[0][1],sr,sc,start);
	if(p.p[1][0]!=-1)
		end=toB(p.p[1][0],p.p[1][1],sr,sc+p.p[0][1],end+1);
	if(p.p[2][0]!=-1)
		end=toB(p.p[2][0],p.p[2][1],sr+p.p[0][0],sc,end+1);
	if(p.p[2][0]!=-1&&p.p[1][0]!=-1)
		end=toB(p.p[3][0],p.p[3][1],sr+p.p[0][0],sc+p.p[0][1],end+1);;
	return end;
}
void toD(int r,int c,int sr,int sc){
	bool same=true;
	for(int i=0;i<r&&same;i++){
		for(int j=0;j<c&&same;j++){
			if(result[sr+i][sc+j]!=result[sr][sc]){
				same=false;
			}
		}
	}
	if(same){
		cout<<result[sr][sc];
		checkNewLine();
		return;
	}
	cout<<'D';
	checkNewLine();
	Part p=getPart(r,c);
	toD(p.p[0][0],p.p[0][1],sr,sc);
	if(p.p[1][0]!=-1)
		toD(p.p[1][0],p.p[1][1],sr,sc+p.p[0][1]);
	if(p.p[2][0]!=-1)
		toD(p.p[2][0],p.p[2][1],sr+p.p[0][0],sc);
	if(p.p[2][0]!=-1&&p.p[1][0]!=-1)
		toD(p.p[3][0],p.p[3][1],sr+p.p[0][0],sc+p.p[0][1]);
}
void createResult(){
	char ch;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			cin>>ch;
			result[i][j]=(ch-'0');
		}
}
int main(){
	while(cin>>ch){
		if(ch=="#")
			break;
		cin>>r>>c;
		if(r!=0&&c!=0){
			if(ch=="D"){	
				counter=0;
				cout<<'B'<<setw(4)<<r<<setw(4)<<c<<endl;
				toB(r,c,0,0,0);
				for(int i=0;i<r;i++)
					for(int j=0;j<c;j++){
						cout<<result[i][j];
						checkNewLine();
					}
			    if(counter!=0)
				 cout<<endl;
			}
			else{
				createResult();	
				cout<<'D'<<setw(4)<<r<<setw(4)<<c<<endl;
				counter=0;
				toD(r,c,0,0);
				if(counter!=0)
				 cout<<endl;
			}
		}
		else{
			if(ch=="D")
				cout<<'B'<<setw(4)<<r<<setw(4)<<c<<endl<<endl;
			else
				cout<<'D'<<setw(4)<<r<<setw(4)<<c<<endl<<endl;
		}
	}
	return 0;
}