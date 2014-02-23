#include <iostream>
#include <string.h>
using namespace std;

bool marked[5][5];
int num[5][5];
int N;
int order[75];
int main(){
	cin>>N;
	for(int p=0;p<N;p++){
		num[2][2]=-1;
		memset(marked,false,sizeof(marked));
		marked[2][2]=true;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++){
				if(i!=2)
					cin>>num[i][j];
				else{
					if(j<2)
						cin>>num[i][j];
					else if(j>2)
						cin>>num[i][j];
					else
						continue;
				}
			}
			for(int i=0;i<75;i++)
				cin>>order[i];
			for(int i=0;i<75;i++){
				int n=order[i];
				for(int r=0;r<5;r++)
					for(int c=0;c<5;c++)
						if(num[r][c]==n){
							marked[r][c]=true;
						}
						bool bingo=false;
						for(int r=0;r<5;r++){
							bool bi=true;
							for(int c=0;c<5;c++)
								if(!marked[r][c]){
									bi=false;
									break;
								}
								if(bi){
									bingo=true;
									break;
								}
						}
						if(!bingo){
							for(int c=0;c<5;c++){
								bool bi=true;
								for(int r=0;r<5;r++)
									if(!marked[r][c]){
										bi=false;
										break;
									}
									if(bi){
										bingo=true;
										break;
									}
							}
						}

						if(!bingo){
							if((marked[0][0]&&marked[1][1]&&marked[3][3]&&marked[4][4])||(marked[0][4]&&marked[1][3]&&marked[3][1]&&marked[4][0]))
								bingo=true;
						}
						if(bingo){
							cout<<"BINGO after "<<i+1<<" numbers announced"<<endl;
							break;
						}
			}
	}
	return 0;
}