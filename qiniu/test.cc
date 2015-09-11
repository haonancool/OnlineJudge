#include <iostream>
#include <sstream>
#include <string>
#include "number.h"

using namespace std;

int main() {
	string line;
	getline(cin, line);
	istringstream ss(line);
	string str;
	int base;
	ss >> str >> base;
	Number lhs(str, base);
	getline(cin, line);
	ss.clear();
	ss.str(line);
	ss >> str >> base;
	Number rhs(str, base);
	return 0;
}