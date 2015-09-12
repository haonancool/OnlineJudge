#include "number.h"
#include "helper.h"
#include <sstream>
#include <algorithm>

using namespace std;

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
	addIntegral(integral_, other.integral_, newBase);
	int carry = addFraction(fraction_, other.fraction_, newBase);
	if (carry)
		addOne(integral_, newBase, 0);
	return *this;
}

void Number::toBase(int base) {
	if (base_ == base)
		return;
	vector<int> newIntegral;
	reverse(integral_.begin(), integral_.end());
	for (int i = 0; i < integral_.size(); i++) {
		vector<int> tmp = transformDigit(integral_[i], i, base_, base);
		addIntegral(newIntegral, tmp, base);
	}
	integral_ = newIntegral;
	vector<int> newFration;
	for (int i = 0; i < fraction_.size(); i++) {
		vector<int> tmp = transformDigit(fraction_[i], i + 1, base / base_, base);
		reverse(tmp.begin(), tmp.end());
		while (tmp.size() < i + 1)
			tmp.push_back(0);
		reverse(tmp.begin(), tmp.end());
		addFraction(newFration, tmp, base);
	}
	fraction_ = newFration;
	base_ = base;
}