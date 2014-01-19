#include <iostream>

using namespace std;

int r,c,cc[1000][1000];
char m[1000][1000];
int adj[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{1,-1},{-1,1}};
bool avail(int a,int b){
	return (0<=a&&a<r)&&(0<=b&&b<c);
}
int main(){
	int counter;
	int tcase=1;
	cin>>r>>c;
	do{
		if(r==0&&c==0)
			break;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>m[i][j];

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				counter=0;
				if(m[i][j]=='*'){
					cc[i][j]=-1;
					continue;
				}
				for(int k=0;k<8;k++){
					int a=i+adj[k][0];
					int b=j+adj[k][1];
					if(avail(a,b)){
						counter+=(m[a][b]=='*');
					}
				}
				cc[i][j]=counter;
			}
			cout<<"Field #"<<tcase<<":"<<endl;
        for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(cc[i][j]!=-1)
					cout<<cc[i][j];
				else
					cout<<'*';
			}
			cout<<endl;
		}
		cin>>r>>c;
		if(!(r==0&&c==0))
			cout<<endl;
		else
			break;
		tcase++;
	}while(true);
}