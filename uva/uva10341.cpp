#include <iostream>
#include <cmath>
#include <iomanip>
#define e 2.71828182845904523536
#define EPS pow(e,-9)
using namespace std;

double p, q, r, s, t, u,lo,hi,mid,ans;
bool lower, upper,overshot;
bool getSign(double x){
	return x > 0;
}
double cal(double x){
	return p*pow(e, -x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
bool solved(double x){
	double rv = cal(x);
	if (abs(rv) < 0.000001)
		return true;
	else{
		if (getSign(rv) == upper)
			overshot = true;
		else
			overshot = false;
		return false;
	}
}
int main(){
	while (cin >> p >> q >> r >> s >> t >> u){
		ans = -1;
		hi = 1.0;
		lo = 0;
		lower = getSign(cal(lo));
		upper = getSign(cal(hi));
		while (hi - lo >= 0.0000000001){
			mid = (hi + lo) / 2.0;
			if (solved(mid)){
				ans = mid;
				break;
			}
			else{
				if (overshot)
					hi = mid;
				else
					lo = mid;
			}
		}
		if (ans == -1)
			cout << "No solution" << endl;
		else
			cout << fixed<<setprecision(4)<<ans << endl;
	}
	return 0;
}