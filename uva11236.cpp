#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string toString(int n){
	ostringstream oss;
	oss<<n;
	return oss.str();
}
string format(int n){
	string s=toString(n/100)+".";
	string s2=toString(n-(n/100)*100);
	if(s2=="0")
		s2="00";
	else if(s2.size()==1)
		s2='0'+s2;
	return s+s2;
}
int main(){
	int sum=0;
	for(long long a=1;a<=1997&&2000-a-2>=a+2;a++)
		for(long long b=a;b<=2000-a&&2000-a-b-1>=b+1;b++)
			for(long long c=b;c<=2000-a-b&&2000-a-b-c>=c+1;c++)
				{
					long long upper=(a+b+c)*1000000;
					long long lower=a*b*c-1000000;
					if(lower==0||upper%lower!=0||lower<=0)
						continue;
					long long d=upper/lower;
					if(a+b+c+d>2000)
						continue;
					if(d<c)
						continue;
					cout<<format(a)<<" "<<format(b)<<" "<<format(c)<<" "<<format(d)<<endl;
					sum++;
				}
    //cout<<sum<<endl;
	return 0;
}