#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v,f,p,output;
int maxLength;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva481.in");
ofstream fout("uva481.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int binarySearch(int k){
	int head=1,tail=maxLength,middle;
	if(head>tail)
		return 0;
	while(head<tail){
		middle=(head+tail+1)/2;
		if(v[f[middle]]<k){
			head=middle;
		}
		else{
			tail=middle-1;
		}	
	}
	if(v[f[head]]<k)
	 return head;
	else
	 return 0;
}
int main(){
	redirect();
	int tmp;
	while(cin>>tmp){
		v.push_back(tmp);
		f.push_back(-1);
		p.push_back(-1);
	}
	maxLength=0;
	for(int i=0;i<v.size();i++){
		int j=binarySearch(v[i]);
			p[i]=f[j];
			if(j==maxLength||v[i]<v[f[j+1]]){
				f[j+1]=i;
				maxLength=max(maxLength,j+1);
			}
	}
	int current=f[maxLength];
	while(current!=-1){
		output.push_back(v[current]);
		current=p[current];
	}
	cout<<maxLength<<endl;
	cout<<'-'<<endl;
	for(int i=output.size()-1;i>=0;i--)
		cout<<output[i]<<endl;
	return 0;
}