#include <iostream>
#include  <stdlib.h>
#include <string.h>
using namespace std;

int m[8];
bool used[8];
int t,minimum,current;
bool check(int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(abs(m[i]-m[j])==abs(j-i))
				return false;
	return true;
}
void search(int pos){
	if(pos==8){
		if(check(pos)){
			if(current<minimum)
				minimum=current;
		}
		return;
	}
	if(!check(pos)){
		return;
	}
	if(!used[m[pos]]){
		used[m[pos]]=true;
		search(pos+1);
		used[m[pos]]=false;
	}
	int ori=m[pos];
	for(int i=0;i<8;i++)
		if(i!=ori&&!used[i]){
			current++;
			m[pos]=i;
			used[i]=true;
			search(pos+1);
			used[i]=false;
			m[pos]=ori;
			current--;
		}
}
int main(){
	int counter=0;
	while(cin>>t){
		counter++;
		cout<<"Case "<<counter<<": ";
		m[0]=t-1;
		for(int i=0;i<7;i++){
			cin>>t;
			m[i+1]=t-1;
		}
		memset(used,false,sizeof(used));
		minimum=2147483647;
		current=0;
		search(0);
		cout<<minimum<<endl;
	}
	return 0;
}