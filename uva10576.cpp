#include <iostream>

using namespace std;
int m[12];
int s,d,maximum,current;
bool check(){
	for(int i=0;i<8;i++){
		int sum=0;
		for(int j=0;j<5;j++){
			sum+=m[i+j];
		}
		if(sum>=0)
			return false;
	}
	return true;
}
void search(int pos){
	if(pos==12){
		if(check()){
			if(current>maximum)
				maximum=current;
		}
		return;
	}
	m[pos]=s;
	current+=s;
	search(pos+1);
	current-=s;
	m[pos]=-d;
	current-=d;
	search(pos+1);
	current+=d;
}
int main(){
	while(cin>>s>>d){
		maximum=-2147483648;
		current=0;
		search(0);
		if(maximum<0)
			cout<<"Deficit"<<endl;
		else
			cout<<maximum<<endl;
	}
	return 0;
}