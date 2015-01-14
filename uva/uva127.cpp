//#define DEBUG
#include <fstream>
#include <iostream>
#include <string>
#include <list>
using namespace std;
#ifdef DEBUG
ifstream fin("uva127.in");
ofstream fout("uva127.out");
#endif

class STACK{
	char s[52][2];
	int n;
public:
	STACK():n(0){}
	void push(char *ch){
		s[n][0]=ch[0];
		s[n][1]=ch[1];
		n++;
	}
	void pop(){
		n--;
	}
	char *top(){
		return s[n-1];
	}
	int size(){
		return n;
	}
};
list<STACK> piles;
string tmp;
list<STACK>::iterator last;
int counter=0;
bool allow(char *a,char *b){
	return (a[0]==b[0]||a[1]==b[1]);
}

bool move(){
	list<STACK>::iterator it,tmp;
	for(it=last;it!=piles.end();it++){
		if(counter>=3){
		  tmp=it;
		  tmp--;tmp--;tmp--;
		  if(allow(it->top(),tmp->top())){
			  tmp->push(it->top());
			  it->pop();
			  if(it->size()==0)
				  piles.erase(it);
			  last=tmp;
			  counter-=3;
			  return true;
		  }
		  tmp=it;
		  tmp--;
		  if(allow(it->top(),tmp->top())){
			  tmp->push(it->top());
			  it->pop();
			  if(it->size()==0)
				  piles.erase(it);
			  last=tmp;
			  counter-=1;
			  return true;
		  }
		}
		else if(counter>=1){
		  tmp=it;
		  tmp--;
		  if(allow(it->top(),tmp->top())){
			  tmp->push(it->top());
			  it->pop();
			  if(it->size()==0)
				  piles.erase(it);
			  last=tmp;
			  counter-=1;
			  return true;
		  }
		}
		counter++;
	}
	return false;
}

void display(){
#ifdef DEBUG
	fout<<piles.size()<<" piles remaining:";
	for(list<STACK>::iterator it=piles.begin();it!=piles.end();it++){
		fout<<" "<<it->size();
	}
	fout<<endl;
#else
	if(piles.size()==1)
		cout<<piles.size()<<" pile remaining:";
	else
	    cout<<piles.size()<<" piles remaining:";
	for(list<STACK>::iterator it=piles.begin();it!=piles.end();it++){
		cout<<" "<<it->size();
	}
	cout<<endl;
#endif
}

int main(){
  while(true){
	piles.clear();
	counter=0;
	for(int i=0;i<52;i++){
		STACK s;
		#ifdef DEBUG
		fin>>tmp;
		#else
		cin>>tmp;
		#endif
		if(tmp=="#")
			return 0;
		char ch[2];
		ch[0]=tmp[0];
		ch[1]=tmp[1];
		s.push(ch);
		piles.push_back(s);
	}
	last=piles.begin();
	while(true){
		if(!move()) break;
	}

	display();
  }
  return 0;
}
