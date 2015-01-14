#include <iostream>

using namespace std;

long long T,N,v[1000],f[1000],s[1000];
int main(){
    cin>>T;
    for(int t=0;t<T;t++){
    	cin>>N;
    	f[0]=1;
    	for(int i=0;i<N;i++){
    		cin>>v[i];
    		if(i>0){
    			s[i]=s[i-1]+v[i];
    		}
    		else{
    			s[i]=v[i];
    		}
    	}
    	for(int i=0;i<N;i++){
    		for(int j=N-1;j>=0;j--){
               if(s[j]<v[i]){
            	   f[i]=f[j]+1;
            	   break;
               }
    		}
    	}
    	cout<<f[N-1]<<endl;
    }
	return 0;
}
