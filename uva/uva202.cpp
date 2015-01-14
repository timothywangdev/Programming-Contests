#include <iostream>
#include <vector>
using namespace std;

vector<int> remain;
vector<int> deci;
int intPart;
int a,b,pos,oa,ob;
bool exist(int n){
	for(int i=0;i<remain.size();i++)
		if(n==remain[i]){
			pos=i;
			return true;
		}
	return false;
}
void display(){
   cout<<oa<<"/"<<ob<<" = "<<intPart<<".";
   if(a==0){
	   for(int i=0;i<deci.size();i++)
		   cout<<deci[i];
	   cout<<"(0)"<<endl;
	   cout<<"   1 = number of digits in repeating cycle"<<endl;
   }
   else{
	   int counter=0;
       for(int i=0;i<pos;i++)
    	   cout<<deci[i];
       cout<<"(";
       counter=pos;
       for(int i=pos;i<deci.size();i++){
    	   counter++;
    	   if(counter>50){
    		   cout<<"...)"<<endl;
    		   break;
    	   }
    	   cout<<deci[i];
       }
       if(counter<=50)
    	   cout<<")"<<endl;
       cout<<"   "<<deci.size()-pos<<" = number of digits in repeating cycle"<<endl;
   }
}
void decimal(){
    a*=10;
    if(a==0){
    	display();
    	return;
    }
    if(exist(a)){
        	display();
        	return;
    }
    else{
    	remain.push_back(a);
    }
    int k;
    for(int i=9;i>=0;i--)
    	if(b*i<=a){
           k=i;
           break;
    	}
    a=a-k*b;
    deci.push_back(k);
    decimal();
}
void integerPart(){
 intPart=a/b;
 if(a>=b){
	 a=a-intPart*b;
 }
}
int first=true;
int main(){
    while(cin>>a>>b){
    	/*
    	if(!first)
    		cout<<endl;
    	else
    		first=false;
    		*/
    	oa=a;
    	ob=b;
    	pos=-1;
       remain.clear();
       deci.clear();
       integerPart();
       decimal();
       cout<<endl;
    }
	return 0;
}
