#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva1061.in");
ofstream fout("uva1061.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
map<string,string> toShort;
vector<string> v;
string allABO[4]={"A","B","AB","O"};
string allRh[2]={"+","-"};
string getABO(string &t){
	string rv;
	for(int i=0;i<t.length();i++){
		if(t[i]=='A'||t[i]=='B'||t[i]=='O')
			rv.push_back(t[i]);
		else
			break;
	}
	return rv;
}
string getRh(string &t){
	string rv;
	for(int i=0;i<t.length();i++){
		if(t[i]=='+'||t[i]=='-')
			rv.push_back(t[i]);
	}
	return rv;
}
class bloodType{
public:
	vector<string> ABO;
	vector<string> Rh;
	bloodType(string t){
		string abo=getABO(t);
		string rh=getRh(t);
		if(abo=="A"){
			ABO.push_back("AA");
			ABO.push_back("AO");
		}
		else if(abo=="B"){
			ABO.push_back("BB");
			ABO.push_back("BO");
		}
		else if(abo=="AB"){
			ABO.push_back("AB");
		}
		else{
			ABO.push_back("OO");
		}
		if(rh=="+"){
			Rh.push_back("++");
			Rh.push_back("+-");
		}
		else{
			Rh.push_back("--");
		}
	}
};
void addBloodType(string abo,string rh){
	sort(abo.begin(),abo.end());
	sort(rh.begin(),rh.end());

	string s=toShort[abo]+toShort[rh];
	if(find(v.begin(),v.end(),s)==v.end()){
		v.push_back(s);
	}
}
void childBloodType(const bloodType &a, const bloodType&b){
	v.clear();
	string abo,rh;
	for(int ai=0;ai<a.ABO.size();ai++)
		for(int aj=0;aj<2;aj++)
			for(int bi=0;bi<b.ABO.size();bi++)
				for(int bj=0;bj<2;bj++){
					abo.clear();
					abo.push_back(a.ABO[ai][aj]);
					abo.push_back(b.ABO[bi][bj]);

					for(int ak=0;ak<a.Rh.size();ak++)
						for(int arj=0;arj<2;arj++)
							for(int bk=0;bk<b.Rh.size();bk++)
								for(int brj=0;brj<2;brj++){
									rh.clear();
									rh.push_back(a.Rh[ak][arj]);
									rh.push_back(b.Rh[bk][brj]);
									addBloodType(abo,rh);
								}
				}
}
int counter=0;
int main(){
	redirect();
	toShort["++"]="+";
	toShort["+-"]="+";
	toShort["--"]="-";

	toShort["AA"]="A";
	toShort["AO"]="A";
	toShort["BB"]="B";
	toShort["BO"]="B";
	toShort["AB"]="AB";
	toShort["OO"]="O";

	string p1,p2,c;
	while(cin>>p1>>p2>>c){
		if(p1=="E"&&p2=="N"&&c=="D")
			break;
		counter++;
		cout<<"Case "<<counter<<": ";
		if(c=="?"){
			cout<<p1<<" "<<p2<<" ";
			bloodType pbt1(p1),pbt2(p2);
			childBloodType(pbt1,pbt2);
			if(v.size()==1)
				cout<<v[0]<<endl;
			else{
				cout<<"{";
				for(int i=0;i<v.size();i++){
					cout<<v[i];
					if(i!=v.size()-1)
						cout<<", ";

				}
				cout<<"}"<<endl;
			}
		}
		else{
			vector<string> parent;
			string target;
			if(p1!="?")
				target=p1;
			else
				target=p2;
			bloodType t(target);
			for(int i=0;i<4;i++){
				for(int j=0;j<2;j++){
					string fullType=allABO[i]+allRh[j];
					bloodType test(fullType);
					childBloodType(t,test);
					if(find(v.begin(),v.end(),c)!=v.end()){
						parent.push_back(fullType);
					}
				}
			}
			if(p1!="?")
				cout<<p1<<" ";
			if(parent.size()!=0){
				if(parent.size()==1)
					cout<<parent[0]<<endl;
				else{
					cout<<"{";
					for(int i=0;i<parent.size();i++){
						cout<<parent[i];
						if(i!=parent.size()-1)
							cout<<", ";

					}
					cout<<"} ";
				}
			}
			else{
				cout<<"IMPOSSIBLE ";
			}
			if(p2!="?")
				cout<<p2<<" ";
			cout<<c<<endl;
		}
	}
	return 0;
}