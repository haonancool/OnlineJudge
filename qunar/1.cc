#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Version {
	int major;
	int minor;
	int patch;
	string line;
	Version() : major(0), minor(0), patch(0) {}
};

bool operator<(const Version &lhs, const Version &rhs) {
	if (lhs.major < rhs.major) {
		return true;
	} else if (lhs.major == rhs.major) {
		if (lhs.minor < rhs.minor)
			return true;
		else if (lhs.minor == rhs.minor && lhs.patch < rhs.patch)
			return true;
	}
	return false;
}

Version getVersion(const string &line) {
	Version ver;
	ver.line = line;
	int pos = line.find('.');
	ver.major = atoi(line.substr(0, pos).c_str());
	int last = pos + 1;
	pos = line.find('.', last);
	if (pos > 0) {
		ver.minor = atoi(line.substr(last, -1).c_str());
	} else {
		ver.minor = atoi(line.substr(last, pos - last).c_str());
		last = pos + 1;
		ver.patch = atoi(line.substr(last, -1).c_str());
	}
	return ver;
}

int main() {
	string line;
	getline(cin, line);
	istringstream ss(line);
	int n;
	ss >> n;
	Version latest;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		Version tmp = getVersion(line);
		if (tmp.minor % 2 == 0 && latest < tmp) {
			latest = tmp;
			flag = true;
		}
	}
	if (flag)
		cout << latest.line;
	else
		cout << "no stable available";


	return 0;
}
