#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N,n,tmp;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>n;
		n--;
		v.clear();
		for(int j=0;j<n;j++){
			cin>>tmp;
			v.push_back(tmp);
		}
		int maxHead=0,maxTail,currentHead=0,sum=0,maxsum=-2147483648;
		for(int i=0;i<v.size();i++){
			sum+=v[i];
			if(sum>maxsum){
				maxHead=currentHead;
				maxTail=i;
	            maxsum=sum;
			}
			else if(sum==maxsum&&maxHead-maxTail<i-currentHead){
				maxHead=currentHead;
				maxTail=i;
			}
			if(sum<0){
				sum=0;
				currentHead=i+1;
			}
		}
		if(maxsum>=0){
			cout<<"The nicest part of route "<<i+1<<" is between stops "<<maxHead+1<<" and "<<maxTail+2<<endl;
		}
		else{
			cout<<"Route "<<i+1<<" has no nice parts"<<endl;
		}
	}
	return 0;
}