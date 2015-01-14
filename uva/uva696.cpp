#include <iostream>

using namespace std;
int R,C,maximum;
int main(){
	while(cin>>R>>C){
		if(R==0&&C==0)
			break;
		if(R>=3&&C>=3){
			int odd,even,oddL,evenL;
			if(C%2==0){
				odd=even=C/2;
			}
			else{
				even=(C+1)/2;
				odd=even-1;
			}
			if(R%2==1){
				oddL=(R+1)/2;
				evenL=oddL-1;
			}
			else{
				oddL=evenL=R/2;
			}
			maximum=max(odd*oddL+even*evenL,even*oddL+odd*evenL);
		}
		else if(R==1||C==1){
			if(R==1)
				maximum=C;
			else
				maximum=R;
		}
		else if(R==2||C==2){
			int a,b;
			if(R==2){
				a=R;
				b=C;
			}
			else{
				a=C;
				b=R;
			}
			if(b%2==1)
				maximum=b+1;
			else{
				if((b/2)%2==1){
					maximum=b+2;
				}
				else{
					maximum=b;
				}
			}
		}
		
		cout<<maximum<<" knights may be placed on a "<<R<<" row "<<C<<" column board."<<endl;
	}
	return 0;
}