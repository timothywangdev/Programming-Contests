#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
	long long x, y;
	double l, r, d, a, b;
	while (cin>>x) {
		y = x;
		int c = 0;
		while (y) {
			c++;
			y /= 10;
		}

		l = log((double)x) / log((double)2);
		r = log((double)(x + 1)) / log((double)2);
		d = log((double)10) / log((double)2);

		for (int i = c + 1;; i++) {
			a = l + i * d;
			b = r + i * d;

			if (ceil(a) <= floor(b)) {
				printf("%.0lf\n", ceil(a));
				break;
			}
			else if (i == 1000000) {
				printf("no power of 2\n");
				break;
			}
		}
	}
	return 0;
}

