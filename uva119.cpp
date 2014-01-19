//#decine DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#ifdef DEBUG
ifstream cin("uva119.in");
ofstream cout("uva119.out");

#endif
map<string,int> toArray;
map<int,string> toName;
int net[10];
int N,spend,number;
string name,given;
int main(){
	cin>>N;
	while(true){
		for(int i=0;i<N;i++){
			cin>>name;
            toArray[name]=i;
			toName[i]=name;
			net[i]=0;
		}
		for(int i=0;i<N;i++){
            cin>>name>>spend>>number;
			if(number!=0)
             net[toArray[name]]+=-number*(spend/number);
			for(int j=0;j<number;j++){
               cin>>given;
               net[toArray[given]]+=spend/number;
			}

		}
		for(int i=0;i<N;i++){
			//if(net[i]!=0)
              cout<<toName[i]<<" "<<net[i]<<endl;
		}
		if(cin>>N)
		 cout<<endl;
		else
		 break;
	}
	return 0;
}