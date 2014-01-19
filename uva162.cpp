#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva162.in");
ofstream fout("uva162.out");
#endif
// 0 dealer 1 non-dealer
vector<string> deck,  p[2];
int pay[2];
string s;

void swap(string &a,string &b){
    string tmp=a;
	a=b;
	b=tmp;
}
void reverseDeck(){
   for(unsigned int i=0;i<deck.size()/2;i++){
       swap(deck[i],deck[deck.size()-i-1]);
   }
}
void getPile(bool counter){
	reverseDeck();
	p[counter].insert(p[counter].begin(),deck.begin(),deck.end());
	deck.clear();
}
bool ordinary(string s){
    return !(s[1]=='A'||s[1]=='K'||s[1]=='Q'||s[1]=='J');
}
int getAmount(string s){
    if(s[1]=='J')
		return 1;
	else if(s[1]=='Q')
		return 2;
	else if(s[1]=='K')
		return 3;
	else if(s[1]=='A')
		return 4;
}
void process(){
	for(int i=0;i<(int)deck.size();i++)
		p[1-i%2].push_back(deck[i]);

	pay[0]=pay[1]=-1;
	deck.clear();
	bool counter=true;
	while(p[counter].size()!=0){

		deck.push_back(p[counter][p[counter].size()-1]);
		p[counter].pop_back();
		pay[counter]--;
		if(!ordinary(deck[deck.size()-1])){
			pay[1-counter]=getAmount(deck[deck.size()-1]);
			pay[counter]=-1;
		}

		// Payment completed
		if(pay[counter]==0){
            pay[counter]=-1;
			// Takes the whole pile and put it under other's cards
			getPile(1-counter);
			// Change to the guy who played the pay card
		}
		else if(pay[counter]>0){
			// Payment is not compelted
            counter=1-counter;	
		}

		counter=1-counter;
	}
	cout<<1-counter+1<<setw(3)<<p[1-counter].size()<<endl;


}
int main(){
	while(cin>>s){
		if(s[0]=='#')
			break;
		deck.push_back(s);	
		if(deck.size()==52){
			process();
			deck.clear();
			p[0].clear();
			p[1].clear();
		}
	}
	return 0;
}