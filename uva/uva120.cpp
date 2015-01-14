#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
#ifdef DEBUG
ifstream fin("uva120.in");
ofstream fout("uva120.out");
#endif

int stack[30],N,current;
string line;

void swap(int a,int b){
	if(a==b) return;
     stack[a]=stack[a]+stack[b];
	 stack[b]=stack[a]-stack[b];
	 stack[a]=stack[a]-stack[b];
}
void flip(int pos){
	cout<<N-pos<<" ";
	for(int i=0;i<=pos/2;i++){
       swap(i,pos-i);
	}
}
int findMax(int start,int end){
    int maximum=0,themax=-1;
	for(int i=start;i<=end;i++)
		if(stack[i]>maximum){
            maximum=stack[i];
			themax=i;
		}
	return themax;
}
void process(int start,int end){
	if(start==end)
		return;
    int pos=findMax(start,end);
	if(pos==0){
       flip(end); 
	}else if(pos<end){
       flip(pos);
	   flip(end);
	}
	process(start,end-1);
}

int main(){
	while(getline(cin,line)){
	   N=0; 
       istringstream iss(line);
	   while(iss>>stack[N]){
		  N++;
	   }
	   for(int i=0;i<N-1;i++)
		   cout<<stack[i]<<" ";
	   cout<<stack[N-1]<<endl;
	   process(0,N-1);
	   cout<<"0"<<endl;
	}
	return 0;
}
