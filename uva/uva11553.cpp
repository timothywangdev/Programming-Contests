#include <iostream>
#include <string.h>
using namespace std;

int m[8][8];
bool a[8],b[8];
int T,N;
int searchAlice();
int minimum,current;
void search(int row){
	if(row==N){
		if(current<minimum)
			minimum=current;
		return;
	}
	for(int i=0;i<N;i++)
		if(!b[i]){
			b[i]=true;
			current+=m[row][i];
			search(row+1);
			b[i]=false;
			current-=m[row][i];
		}
}
int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++){
				cin>>m[j][k];
			}
			memset(b,false,sizeof(b));
			minimum=2147483647;
			current=0;
			search(0);
			cout<<minimum<<endl;
	}
	return 0;
}