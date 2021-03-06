#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10901.in");
ofstream fout("uva10901.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
class car{
public:
	int id;
	int a_time;
	int d_time;
	car(int a_time,int id):id(id),a_time(a_time){}
};

queue<car> bank[2],ferry;
vector<car> rv;
int C,N,T,M,L,l,a_time,currTime,counter;
string o_pos;
bool pos;
bool my_sort(const car &a,const car &b){
	return a.id<b.id;
}
bool available(bool pos){
	if(bank[pos].size()&&bank[pos].front().a_time<=l)
		return true;
	else
		return false;
}
bool banksNotAvailable(){
	if(bank[0].size()&&bank[0].front().a_time>currTime&&
		bank[1].size()&&bank[1].front().a_time>currTime)
		return true;
	if(bank[0].size()&&bank[0].front().a_time>currTime&&!bank[1].size())
		return true;
	if(bank[1].size()&&bank[1].front().a_time>currTime&&!bank[0].size())
		return true;
	return false;
}
car getCar(bool pos){
	car tCar=bank[pos].front();
	bank[pos].pop();
	return tCar;
}
void setNextTime(bool pos){
	if(bank[pos].size()&&!bank[1-pos].size())
		currTime=bank[pos].front().a_time;
	else if(!bank[pos].size()&&bank[1-pos].size())
		currTime=bank[1-pos].front().a_time;
	else if(bank[pos].size()&&bank[1-pos].size()){
		if(bank[pos].front().a_time<bank[1-pos].front().a_time)
			currTime=bank[pos].front().a_time;
		else
			currTime=bank[1-pos].front().a_time;
	}
}
int main(){
	redirect();
	cin>>C;
	for(int k=0;k<C;k++){
		cin>>L>>M;
		L*=100;
		counter=M;
		rv.clear();
		for(int i=0;i<M;i++){
			cin>>a_time>>o_pos;
			if(o_pos=="left"){
				bank[0].push(car(a_time,i));
			}
			else{
				bank[1].push(car(a_time,i));
			}
		}
		currTime=0;
		pos=false;
		l=L;
		while(counter){
			while(available(pos)){
				car tCar=getCar(pos);
				l-=tCar.a_time;
				ferry.push(tCar);
			}
			pos=1-pos;
			currTime++;
			while(ferry.size()){
				l=L;
				car tCar=ferry.front();
				ferry.pop();
				tCar.d_time=currTime;
				rv.push_back(tCar);
				counter--;
			}
		}
		cout<<currTime<<endl;
	}

	return 0;
}