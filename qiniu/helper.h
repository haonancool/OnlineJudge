#ifndef HELPER_H
#define HELPER_H

#include <vector>

inline int toDigit(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		return c - 'A' + 36;
	return 0;
}

inline char toAlpha(int n) {
	if (n >= 0 && n <= 9)
		return '0' + n;
	else if (n >= 10 && n <= 35)
		return 'a' + n - 10;
	else
		return 'A' + n - 36;
}

inline int gcd(int a, int b) {
	while (b) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

inline int lcm(int a, int b) {
	int c = gcd(a, b);
	return a / c * b;
}

void addOne(std::vector<int> &vec, int base, int ith);

void addIntegral(std::vector<int> &lhs, const std::vector<int> &rhs, int base);

std::vector<int> transformDigit(int digit, int ith, int oldBase, int newBase);

int addFraction(std::vector<int> &lhs, const std::vector<int> &rhs, int base);

#endif // HELPER_H