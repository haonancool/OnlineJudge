#include <iostream>
#include <sstream>
#include <string>
#include "number.h"
#include "helper.h"

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
	lhs += rhs;
	cout << lhs.toString() << " " << lhs.getBase() << endl;
	return 0;
}