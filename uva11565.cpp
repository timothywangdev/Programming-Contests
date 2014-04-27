#include <iostream>

using namespace std;

int T,A,B,C;
bool found;
int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>A>>B>>C;
		found=false;
		for(int x=-100;x<=100&&!found;x++)
			for(int y=-100;y<=100&&!found;y++)
				for(int z=-100;z<=100&!found;z++)
					if(x!=y&&y!=z&&x!=z){
						if(x+y+z==A&&x*y*z==B&&x*x+y*y+z*z==C)
						{
							cout<<x<<" "<<y<<" "<<z<<endl;
							found=true;
							break;
						}
					}
					if(!found){
						cout<<"No solution."<<endl;
					}
	}
	return 0;
}