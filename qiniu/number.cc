#include "number.h"
#include <sstream>
#include <algorithm>

using namespace std;

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
	return a * b / c;
}

Number::Number(const string &str, int base)
	: base_(base) {
	int width = (base + 61) / 62;
	int int_len = str.find('.');
	int_len = (int_len < 0) ? str.length() : int_len;
	int i = 0;
	if (int_len % width) {
		int n = 0;
		for (; i < int_len % width; i++) {
			n *= 62;
			n += toDigit(str[i]);
		}
		integral_.push_back(n);
	}
	bool isFract = false;
	while (i < str.length()) {
		if ('.' == str[i]) {
			isFract = true;
			i++;
		} else {
			int n = toDigit(str[i]);
			i++;
			for (int j = 1; j < width; j++) {
				n *= 62;
				n += toDigit(str[i]);
				i++;
			}
			if (isFract)
				fraction_.push_back(n);
			else
				integral_.push_back(n);
		}
	}
	if (integral_.empty())
		integral_.push_back(0);
	if (fraction_.empty())
		fraction_.push_back(0);
	reverse(integral_.begin(), integral_.end());
	while (integral_.size() > 1 && 0 == integral_.back())
		integral_.pop_back();
	reverse(integral_.begin(), integral_.end());
	while (fraction_.size() > 1 && 0 == fraction_.back())
		fraction_.pop_back();
}

std::string Number::toString() const {
	ostringstream ss;
	int width = (base_ + 61) / 62;
	string tmp;
	tmp.resize(width);
	for (int i = 0; i < integral_.size(); i++) {
		int n = integral_[i];
		for (int j = width - 1; j >= 0; j--) {
			tmp[j] = toAlpha(n % 62);
			n /= 62;
		}
		ss << tmp;
	}
	if (!(1 == fraction_.size() && fraction_[0] == 0)) {
		ss << '.';
		for (int i = 0; i < fraction_.size(); i++) {
			int n = fraction_[i];
			for (int j = width - 1; j >= 0; j--) {
				tmp[j] = toAlpha(n % 62);
				n /= 62;
			}
			ss << tmp;
		}
	}
	return ss.str();
}

Number& Number::operator+=(const Number &rhs) {
	Number other(rhs);
	int newBase = lcm(base_, other.base_);
	toBase(newBase);
	other.toBase(newBase);
}

void Number::toBase(int base) {
	if (base_ == base)
		return;
	reverse(integral_.begin(), integral_.end());
	vector<int> newIntegral;
	for (int i = 0; i < integral_.size(); i++) {
		vector<int> tmp;
		tmp.push_back(integral_[i]);
		for (int j = 0; j < i; j++) {
			int size = tmp.size();
			for (int k = 0; k < size; k++) {
				tmp[k] *= base_;
				int m = k;
				while (tmp[m] >= base) {
					tmp[m] -= base;
					if (m == tmp.size() - 1)
						tmp.push_back(1);
					else
						tmp[m + 1]++;
					m++;
				}
			}
		}
	}
}
