#include "number.h"
#include <algorithm>

using namespace std;

Number::Number(const string &str, int base)
	: base_(base) {
	int width = (base + 61) / 62;
	int int_len = str.find('.');
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
			n = toDigit(str[i]);
			for (int j = 1; j < width; j++) {
				n *= 62;
				n += toDigit(str[i]);
				i++;
			}
			if (isFract)
				fract_.push_back(n);
			else
				integral_.push_back(n);
		}
	}
	if (integral_.empty())
		integral_.push_back(0);
	if (fract_.empty())
		fract_.push_back(0);
}

int toDigit(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		return c - 'A' + 36;
	return 0;
}
