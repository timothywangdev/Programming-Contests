#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string number[10]={"YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY","YNYYNYY","YNYYYYY","YYYNNNN","YYYYYYY","YYYYNYY"};
string v[11];
bool broken[7];
int N;
bool found;
void search(int pos,int num){
	if(pos==N){
		found=true;
		return;
	}
	for(int i=0;i<7;i++){
		if(v[pos][i]=='Y'&&broken[i])
			return;
		if(number[num][i]=='N'&&v[pos][i]=='Y'){
			return;
		}
		else if(number[num][i]=='Y'&&v[pos][i]=='N'){
			broken[i]=true;
		}
	}
	search(pos+1,num-1);
}
int main(){
	while(cin>>N){
		if(!N)
			break;
		for(int i=0;i<N;i++)
			cin>>v[i];
		for(int i=9;i>=N-1;i--){
			memset(broken,false,sizeof(broken));
			found=false;
			search(0,i);
			if(found)
				break;
		}
		if(found)
			cout<<"MATCH"<<endl;
		else
			cout<<"MISMATCH"<<endl;
	}
	return 0;
}