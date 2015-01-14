#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath> 
using namespace std;
#ifdef DEBUG
ifstream fin("uva190.in");
ofstream cout("uva190.out");
#endif
double X1,X2,X3,Y1,Y2,Y3;
void display1(double h,double k,double r){
	if(h!=0){
		cout<<"(x";
		if(h>0)
			cout<<" - ";
		else{
			cout<<" + ";
			h=abs(h);
		}
		cout<<fixed<<setprecision(3)<<h;
		cout<<")^2 + ";
	}
	else{
		cout<<"x^2 + ";
	}
	if(k!=0){
		cout<<"(y";
		if(k>0)
			cout<<" - ";
		else{
			cout<<" + ";
			k=abs(k);
		}

		cout<<fixed<<setprecision(3)<<k;
		cout<<")^2 = ";
	}
	else{
		cout<<"y^2 = ";
	}
	cout<<fixed<<setprecision(3)<<r;
	cout<<"^2"<<endl;
}
void display2(double c,double d,double e){
	cout<<"x^2 + y^2";
	if(c>0)
		cout<<" + "<<fixed<<setprecision(3)<<c;
	else if(c<0){
		c=abs(c);
		cout<<" - "<<fixed<<setprecision(3)<<c;
	}
	if(c!=0)
	 cout<<"x";
	if(d>0)
		cout<<" + "<<fixed<<setprecision(3)<<d;
	else if(d<0){
		d=abs(d);
		cout<<" - "<<fixed<<setprecision(3)<<d;
	}
	if(d!=0)
	 cout<<"y";
	if(e>0)
		cout<<" + "<<fixed<<setprecision(3)<<e;
	else if(e<0){
		e=abs(e);
		cout<<" - "<<fixed<<setprecision(3)<<e;
	}
	cout<<" = 0"<<endl;
	if(!cin.eof())
		cout<<endl;
}
void process(){
	if(X1==X2&&Y2==Y3){
		double h=min(X2,X3)+abs(X2-X3)/2;
		double k=min(Y1,Y2)+abs(Y1-Y2)/2;
		double r=sqrt((X1-h)*(X1-h)+(Y1-k)*(Y1-k));
		double c=-2*h;
		double d=-2*k;
		double e=h*h+k*k-r*r;
		display1(h,k,r);
		display2(c,d,e);
		return;
	}
	else if(X1==X2){
		swap(X1,X3);
		swap(Y1,Y3);
	}
	else if(Y2==Y3){
		swap(X1,X3);
		swap(Y1,Y3);
	}
	double c1=(X1+X2)/2,
		c2=(Y2-Y1)/(2*(X1-X2)),
		c3=Y2+Y1,
		c4=(X2-X3)/(Y3-Y2);
	double k=(c4*X2+c4*X3-2*c4*c1+2*c4*c2*c3-Y3-Y2)/(4*c4*c2-2);
	double h=c1-c2*(c3-2*k);
	double r=sqrt((X1-h)*(X1-h)+(Y1-k)*(Y1-k));
	double c=-2*h;
	double d=-2*k;
	double e=h*h+k*k-r*r;
	//cout<<h<<" "<<k<<" "<<r<<endl;
	display1(h,k,r);
	display2(c,d,e);

}
int main(){
	while(cin>>X1>>Y1>>X2>>Y2>>X3>>Y3){
		process();
	}
	return 0;
}