#include <iostream>
#include <math.h>

using std::cout; using std::cin;

const double PI = 3.1415926;

double test() {
	int V, D;
	cin >> V >> D;
	double tmp = 9.8 * D / V / V;
	if (tmp > 1) tmp = 1;
	double angle = asin(tmp) * 90 / PI;
	return angle;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		double angle = test();
		cout << "Case #" << i << ": " << angle << "\n";
	}
	return 0;
}
