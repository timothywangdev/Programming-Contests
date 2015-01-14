#include <iostream>
#include <string>
using namespace std;
//#define DEBUG
//#include <fstream>
#ifdef DEBUG
ifstream fin("uva10141.in");
ofstream fout("uva10141.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
double cost,bestCost;
string bestName,s,name;
int n,p,k,bestCom;
bool first=true;
int main(){
	redirect();
	int counter=0;
	while(cin>>n>>p){
		if(n==0&&p==0)
			break;
		if(!first)
			cout<<endl;
		else
			first=false;
		counter++;
		bestCom=-1000;
		bestCost=0;
		getline(cin,s);
		for(int i=0;i<n;i++){
			getline(cin,s);
		}
		for(int i=0;i<p;i++){
			getline(cin,name);
			cin>>cost>>k;
			int total=0;
			if(k>0){
				getline(cin,s);
				for(int j=0;j<k;j++){
					getline(cin,s);
					/*
					if(inCom(s)){
						total++;
					}
					*/
				}
			}
			else{
			  getline(cin,s);
			}
			if(k>bestCom){
				bestCom=k;
				bestName=name;
				bestCost=cost;
			}
			else if(k==bestCom&&bestCost>cost){
				bestName=name;
				bestCost=cost;
			}
		}
		cout<<"RFP #"<<counter<<endl;
		cout<<bestName<<endl;
	}

	return 0;
}
