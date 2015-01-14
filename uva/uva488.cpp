#include <iostream>
#include <fstream>

using namespace std;
#ifdef DEBUG
ifstream cin("uva488.in");
ofstream cout("uva488.out");
#endif
int a,f,n;
void display(int k){
   for(int i=1;i<=k;i++)
	   cout<<k;
   cout<<endl;
}
void displayA(){
   for(int i=1;i<=a;i++)
	   display(i);
   for(int i=a-1;i>=1;i--)
       display(i); 
}

int main(){
    cin>>n;
	for(int i=1;i<=n;i++){
       cin>>a>>f;
	   for(int j=1;j<=f;j++){
           displayA();
		   if(!(i==n&&j==f))
		      cout<<endl;
	   }
	}
	return 0;
}