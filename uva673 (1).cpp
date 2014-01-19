#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("uva673.in");
ofstream fout("uva673.out");

string s;
int n;

bool check(int s,int e){
    if(e-s+1<0)
		return true;
}
int main(){
    fin>>n;
	for(int i=0;i<n;i++){
       fin>>s;
	   if(check(0,s.length()-1))
		   fout<<"Yes"<<endl;
	   else
		   fout<<"No"<<endl;
	}
	return 0;
}