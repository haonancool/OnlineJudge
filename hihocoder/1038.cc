#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> needs, values;
	for (int i = 0; i < N; i++) {
		int need, value;
		cin >> need >> value;
		needs.push_back(need);
		values.push_back(value);
	}
	vector<int> dp(M + 1, 0);
	for (int i = 0; i < N; i++) {
		for (int j = M; j >= 0; j--) {
			if (j >= needs[i] && dp[j] < dp[j - needs[i]] + values[i])
				dp[j] = dp[j - needs[i]] + values[i];
		}
	}
	cout << dp.back();
	return 0;
}
