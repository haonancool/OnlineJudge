#include "helper.h"
#include <algorithm>

using namespace std;

void addOne(vector<int> &vec, int base, int ith) {
	reverse(vec.begin(), vec.end());
	int carry = 1;
	for (int i = ith; i < vec.size(); i++) {
		int tmp = vec[i] + carry;
		vec[i] = tmp % base;
		carry = tmp / base;
	}
	if (carry)
		vec.push_back(carry);
	reverse(vec.begin(), vec.end());
}

void addIntegral(vector<int> &lhs, const vector<int> &rhs, int base) {
	std::reverse(lhs.begin(), lhs.end());
	int carry = 0;
	int i;
	for (i = 0; i < rhs.size(); i++) {
		int tmp = rhs[rhs.size() - 1 - i] + carry;
		if (i < lhs.size())
			tmp += lhs[i];
		carry = tmp / base;
		if (i >= lhs.size())
			lhs.push_back(tmp % base);
		else
			lhs[i] = tmp % base;
	}
	while (carry) {
		int tmp = carry;
		if (i < lhs.size())
			tmp += lhs[i];
		carry = tmp / base;
		if (i >= lhs.size())
			lhs.push_back(tmp % base);
		else
			lhs[i] = tmp % base;
		i++;
	}
	reverse(lhs.begin(), lhs.end());
}

int addFraction(vector<int> &lhs, const vector<int> &rhs, int base) {
	int len = std::min(lhs.size(), rhs.size());
	for (int i = lhs.size(); i < rhs.size(); i++)
		lhs.push_back(rhs[i]);
	int carry = 0;
	for (int i = len - 1; i >= 0; i--) {
		int tmp = lhs[i] + rhs[i] + carry;
		lhs[i] = tmp % base;
		carry = tmp / base;
	}
	while (lhs.size() > 1 && 0 == lhs.back())
		lhs.pop_back();
	return carry;
}

vector<int> transformDigit(int digit, int ith, int oldBase, int newBase) {
	vector<int> ret;
	ret.push_back(digit);
	for (int i = 0; i < ith; i++) {
		int carry = 0;
		for (int j = 0; j < ret.size(); j++) {
			int tmp = ret[j] * oldBase + carry;
			ret[j] = tmp % newBase;
			carry = tmp / newBase;
		}
		if (carry)
			ret.push_back(carry);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
