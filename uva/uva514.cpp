#include <iostream>
#include <stack>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva514.in");
ofstream fout("uva514.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int v[1000],rail[1000];;
int N;
bool first=true;
bool terminated;
stack<int> s;
int onRailA(int start,int target){
	for(int i=start;i<N;i++)
		if(rail[i]==target)
			return i;
	return -1;
}
int main(){
	redirect();
	while(cin>>N){
		if(N==0)
			break;
		terminated=false;
		while(!terminated){
			while(s.size()!=0)
				s.pop();
			for(int i=0;i<N;i++){
				cin>>v[i];
				if(i==0&&v[0]==0){
					terminated=true;
					break;
				}
			}
			if(!terminated){
				bool possible=true;
				for(int i=1;i<=N;i++)
					rail[i-1]=i;
				int railA=0;
				for(int i=0;i<N;i++){
					int pos=onRailA(railA,v[i]);
					if(pos!=-1){
						for(int j=railA;j<=pos;j++)
							s.push(rail[j]);
						railA=pos+1;
					}
					if(s.top()!=v[i]){
						possible=false;
						break;
					}
					else{
						s.pop();
					}
				}
				if(possible)
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;
			}
		}
		cout<<endl;
	}
}