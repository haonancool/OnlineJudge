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
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < N; j++) {
			if (i + needs[j] <= M && dp[i + needs[j]] < dp[i] + values[j])
				dp[i + needs[j]] = dp[i] + values[j];
		}
	}
	int ret = 0;
	for (int i : dp)
		ret = (ret < i) ? i : ret;
	cout << ret;
	return 0;
}
