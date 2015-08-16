#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::cin;
using std::vector;
using std::string;
using std::sort;

int test() {
	string line;
	getline(cin, line);
	int N = stoi(line);
	vector<string> cards;
	for (int i = 0; i < N; i++) {
		string name;
		getline(cin, name);
		cards.push_back(name);
	}
	int fee = 0;
	for (int i = 1; i < N; i++) {
		string tmp = cards[i];
		int j = i;
		while (j > 0 && cards[j - 1] > tmp) {
			cards[j] = cards[j - 1];
			j--;
		}
		if (j < i) {
			cards[j] = tmp;
			fee++;
		}
	}

	return fee;
}

int main() {
	string line;
	getline(cin, line);
	int T = stoi(line);
	for (int i = 1; i <= T; i++) {
		int fee = test();
		cout << "Case #" << i << ": " << fee << "\n";
	}
	return 0;
}
