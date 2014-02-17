#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva11507.in");
ofstream fout("uva11507.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
struct P{
	int x;
	int y;
	int z;
};

int L;
string s,tmp;
void rotate(string &dir, int &xr, P &p){
	int ox=p.x,oy=p.y,oz=p.z;
	if(dir=="+y"){
		p.x=xr-oy;
		p.y=ox-xr;
	}
	else if(dir=="-y"){
		p.x=oy+xr;
		p.y=-ox+xr;
	}
	else if(dir=="+z"){
		p.x=xr-oz;
		p.z=ox-xr;
	}
	else if(dir=="-z"){
		p.x=oz+xr;
		p.z=-ox+xr;
	}
}
int main(){
	redirect();
    while(cin>>L){
		if(L==0)
			break;
		P p1={L-1,0,0};
		P p2={L,0,0};
		int currentX=L-1;
		getline(cin,s);
		getline(cin,s);
		istringstream iss(s);
		while(iss>>tmp){
			rotate(tmp,currentX,p1);
			rotate(tmp,currentX,p2);
			currentX--;
		}
		p1.x=p2.x-p1.x;
		p1.y=p2.y-p1.y;
		p1.z=p2.z-p1.z;
		if(p1.x>0)
			cout<<"+x";
		else if(p1.x<0)
			cout<<"-x";
		else if(p1.y>0)
			cout<<"+y";
		else if(p1.y<0)
			cout<<"-y";
		else if(p1.z>0)
			cout<<"+z";
		else if(p1.z<0)
			cout<<"-z";
		else
			throw(" Something bad happened!");
		cout<<endl;
	}
	return 0;
}