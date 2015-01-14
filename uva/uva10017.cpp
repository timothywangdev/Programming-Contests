#include <iostream>
using namespace std;

//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10017.in");
ofstream fout("uva10017.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}

int N,M,counter,pcounter=0;
class stack{
private:
	int s[250];
	int size;
public:
	stack(){
		size=0;
	}
	void clear(){
		size=0;
	}
	void push(int k){
		s[size]=k;
		size++;
	}
	int pop(){
		size--;
		return s[size];
	}
	void print(){
		for(int i=0;i<size;i++)
			cout<<" "<<s[i];
	}
	int getSize(){
		return size;
	}
};

stack pile[3];
void print(){
	for(int i=0;i<3;i++){
		cout<<(char)('A'+i)<<"=>";
		if(pile[i].getSize()>0){
			cout<<"  ";
			pile[i].print();
			
		}
		cout<<endl;
	}
	cout<<endl;
}
void command(char from,char to){
	if(counter<=M){
		print();
	}
	pile[to].push(pile[from].pop());
    counter++;
}
char getMiddle(char a,char b){
	if(a!=0&&b!=0)
		return 0;
	else if(a!=1&&b!=1)
		return 1;
	else
		return 2;
}
void f(int n,char from,char to){
	if(counter>M)
		return;
	if(n==1){
		command(from,to);
		return;
	}
	char middle=getMiddle(from,to);
	f(n-1,from,middle);
	if(counter>M)
		return;
	f(1,from,to);
	if(counter>M)
		return;
	f(n-1,middle,to);
}

int main(){
	redirect();
	while(cin>>N>>M){
		if(N==0&&M==0)
			break;
		pcounter++;
		cout<<"Problem #"<<pcounter<<endl<<endl;
		pile[0].clear();
		pile[1].clear();
		pile[2].clear();
		for(int i=N;i>=1;i--)
			pile[0].push(i);
		counter=0;
		f(N,0,2);
		if(counter<=M){
			print();
		}
	}
	return 0;
}