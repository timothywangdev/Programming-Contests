#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
vector<char> rolls;
string s;
bool number(char ch){
	return ('0'<=ch&&ch<='9');
}
int toNum(char ch){
	return (int)(ch-'0');
}
bool strike(char ch){
	return ch=='X';
}
bool spare(char ch){
	return ch=='/';
}
int main(){
	while(getline(cin,s)){
		if(s=="Game Over")
			break;
		rolls.clear();
		istringstream iss(s);
		char ch;
		while(iss>>ch){
			rolls.push_back(ch);
		}
		int total=0;
		int frame=1;
		int biCounter=0;
		int i;
		for(i=0;i<rolls.size();i++){
			if(biCounter==2){
				frame++;
				biCounter=0;
			}
			if(frame>10)
				break;
			if(number(rolls[i])){
				total+=toNum(rolls[i]);
				biCounter++;
			}
			else if(strike(rolls[i])){
				frame++;
				biCounter=0;
				total+=10;
				if(i+1<rolls.size()){
					if(strike(rolls[i+1]))
						total+=10;
					else
						total+=toNum(rolls[i+1]);
				}
				if(i+2<rolls.size()){
					if(strike(rolls[i+2]))
						total+=10;
					else if(spare(rolls[i+2])){
						total+=10-toNum(rolls[i+1]);
					}
				    else{
						total+=toNum(rolls[i+2]);
					}
				}
			}
			else{
				biCounter++;
				total+=10-toNum(rolls[i-1]);
				if(i+1<rolls.size()){
					if(strike(rolls[i+1]))
						total+=10;
					else
						total+=toNum(rolls[i+1]);
				}
			}
		}
		cout<<total<<endl;
	}
	return 0;
}