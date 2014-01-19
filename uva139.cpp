//#define DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
#ifdef DEBUG
ifstream fin("uva139.in");
ofstream fout("uva139.out");
#endif

class code{
    string prefix;
	string dest;
	string number;
	int charge;

public:
	bool legal(string number){
		 int len=number.length()-prefix.length();
         if(number.find("00")==0)
			 return (4<=len)&&(len<=10);
		 else if(number.find("0")==0){
             return (4<=len)&&(len<=7);
		 }
		 else return (number.length()<=15);
	}
    int toInteger(string s){
       istringstream convert(s);
	   int rv;
	   convert>>rv;
	   return rv;
	}

	code(string prefix,string destAandCharge){
       this->prefix=prefix;
	   int pos=destAandCharge.find('$');
	   dest=destAandCharge.substr(0,pos);
	   if(pos!=destAandCharge.length()-1)
	    charge=toInteger(destAandCharge.substr(pos+1,destAandCharge.length()-pos-1));
	   else
	    charge=0;
	}

	bool containsPrefix(string number){
         int pos=number.find(prefix);
		 if(pos!=0)
			 return false;
		 else{
			 if(!legal(number))
				 return false;
			 this->number=number.substr(prefix.length(),number.length()-prefix.length());
			 return true;
		 }
	}
	string getNumber(){
         return number;
	}
	string getDest(){
         return dest;
	}
	int getCost(){
         return charge;
	}
	int calculateCharge(int duration){
         return duration*charge;
	}
};

vector<code> codes;
string s1,s2;
int duration;

string toString(int num){
    ostringstream convert;
	convert<<num;
	return convert.str();
}
string change(int cost){
    int integerPart=cost/100;
	int centPart=cost-integerPart*100;
	if(centPart>=10)
	 return toString(integerPart)+'.'+toString(centPart);
	else if(centPart==0)
     return toString(integerPart)+".00";
	else
     return toString(integerPart)+".0"+toString(centPart);
	
    
}
void display(string fullNumber,string dest,string number,int duration,int cost,int charge){
	#ifdef DEBUG
	if(charge==-1){
       fout<<fullNumber<<" "<<dest<<" "<<number<<" "<<duration<<"  "<<"-1.00"<<endl;
	}
	else{
        fout<<fullNumber<<" "<<dest<<" "<<number<<" "<<duration<<" "<<change(cost)<<" "<<change(charge)<<endl;
	}
	#else
	if(charge==-1){
       cout<<fullNumber<<" "<<dest<<" "<<number<<" "<<duration<<"  "<<"-1.00"<<endl;
	}
	else{
        cout<<fullNumber<<" "<<dest<<" "<<number<<" "<<duration<<" "<<change(cost)<<" "<<change(charge)<<endl;
	}
	#endif
}
void process(string fullNumber,int duration){
	if(fullNumber[0]!='0'){
#ifdef DEBUG
       fout<<fullNumber<<" "<<"Local"<<" "<<fullNumber<<" "<<duration<<" "<<"0.00"<<" "<<"0.00"<<endl;
#else
	   cout<<fullNumber<<" "<<"Local"<<" "<<fullNumber<<" "<<duration<<" "<<"0.00"<<" "<<"0.00"<<endl;
#endif
	   return;
	}

     bool found=false;
	 for(vector<code>::iterator it=codes.begin();it!=codes.end();it++){
		 if(it->containsPrefix(fullNumber)){
			 display(fullNumber,it->getDest(),it->getNumber(),duration,it->getCost(),it->calculateCharge(duration));
			 found=true;
			 break;
		 }
	 }
     if(!found)
		 display(fullNumber,"Unknown","",duration,-1,-1);
}
int main(){
	#ifdef DEBUG
	while(getline(fin,s1)){
       if(s1=="000000")
		   break;
	   int pos=s1.find(' ');
	   s2=s1.substr(pos+1,s1.length()-pos-1);
	   s1=s1.substr(0,pos);
	   code tmp(s1,s2);
	   codes.push_back(tmp);
	}
	while(fin>>s1){
		if(s1[0]=='#')
			break;
		fin>>duration;
        process(s1,duration);
	}
	#else
	while(getline(cin,s1)){
       if(s1=="000000")
		   break;
	   int pos=s1.find(' ');
	   s2=s1.substr(pos+1,s1.length()-pos-1);
	   s1=s1.substr(0,pos);
	   code tmp(s1,s2);
	   codes.push_back(tmp);
	}
	while(cin>>s1){
		if(s1[0]=='#')
			break;
		cin>>duration;
        process(s1,duration);

	}
	#endif
	return 0;
}




