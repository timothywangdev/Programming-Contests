#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class big{
public:
   string data;
   int toInt(char ch){
	  return (int)(ch-'0');
   }
   char toChar(int k){
	   return (char)(k+'0');
   }
   big(string s){
	   string ns;
	   bool allZero=true;
	   for(int i=0;i<s.length();i++){
		   if(s[i]=='0'&&allZero)
			   continue;
		   else{
			   allZero=false;
			   ns.push_back(s[i]);
		   }
	   }
	   for(int i=0;i<ns.length();i++){
		   data.push_back(ns[ns.length()-i-1]);
	   }
   }
   big(){
	   data="";
   }
   void operator=(const big &other){
      data=other.data;
   }
   big unitMulti(int k,int nTen){
        int a,next=0;
        big rv;
        for(int i=0;i<data.size();i++){
           a=toInt(data[i]);
           a=a*k+next;
           next=a/10;
           a=a%10;
           //if(a==0&&next==0)
        	//   break;
           rv.data.push_back(toChar(a));
        }
        if(next!=0)
        	rv.data.push_back(toChar(next));
        if(rv.data.length()==0)
        	return rv;
        if(rv.data.size()==1&&rv.data[0]=='0'){
                	rv.data.clear();
                	return rv;
        }
        string ten;
        for(int i=0;i<nTen;i++)
          ten.push_back('0');
        rv.data=ten+rv.data;

        return rv;
   }
   big operator+(const big &other){
                                                            	  big rv;
	  int a,b,next=0;
      int maxl=max((int)data.length(),(int)other.data.length())+1;
      for(int i=0;i<maxl;i++){
    	 if(i<data.length())
          a=toInt(data[i]);
    	 else
    	  a=0;
    	 if(i<other.data.length())
    	  b=toInt(other.data[i]);
    	 else
    	  b=0;
    	 a=a+b+next;
    	 next=a/10;
    	 a=a%10;
    	 //if(a==0&&next==0)
    	 //	 break;
    	 rv.data.push_back(toChar(a));
      }
      if(next!=0)
        rv.data.push_back(toChar(next));
      return rv;
   }
   big operator*(const big &other){
	    big sum;
        for(int i=0;i<other.data.size();i++){
            big step=unitMulti(toInt(other.data[i]),i);
            sum=sum+step;
        }
        return sum;
   }
   void print(){
	   if(data.length()==0){
		   cout<<"0"<<endl;
		   return;
	   }
	   bool first=true,output=false;
	   for(int i=data.length()-1;i>=0;i--){
		   if(first&&data[i]=='0')
			   continue;
		   if(first&&data[i]!='0')
			  first=false;
		   cout<<data[i];
		   output=true;
	   }
	   if(!output)
		   cout<<"0";
	   cout<<endl;
   }
};
int main(){
	string s1,s2;
	while(cin>>s1){
		cin>>s2;
		big a(s1);
		big b(s2);
		big c=a*b;
		c.print();
	}
	return 0;
}
