#include <iostream>
#include  <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> front,rear,sorted;

int f,r;
double t;
int main(){
	while(cin>>f){
		if(!f)
			break;
		cin>>r;
		front.clear();
		rear.clear();
		sorted.clear();
		for(int i=0;i<f;i++){
			cin>>t;
			front.push_back(t);
		}
		for(int i=0;i<r;i++){
			cin>>t;
			rear.push_back(t);
		}
		for(int i=0;i<f;i++)
			for(int j=0;j<r;j++){
				sorted.push_back(rear[j]/front[i]);
			}
		sort(sorted.begin(),sorted.end());
		double maximum=0;
		for(int i=0;i<sorted.size()-1;i++){
			if(sorted[i+1]/sorted[i]>maximum)
				maximum=sorted[i+1]/sorted[i];
		}
		cout<<fixed<<setprecision(2)<<maximum<<endl;
	}
	return 0;
}