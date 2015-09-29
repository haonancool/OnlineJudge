#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool test0(vector<vector<int>> &A, vector<vector<int>> &B, int N, int oxa, int oya, int oxb, int oyb) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[oxa + i][oya + j] != B[oxb + i][oyb + j])
				return false;
		}
	}
	return true;
}

bool test1(vector<vector<int>> &A, vector<vector<int>> &B, int N, int oxa, int oya, int oxb, int oyb) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[oxa + i][oya + j] != B[oxb + j][oyb + N - 1 - i])
				return false;
		}
	}
	return true;
}

bool test2(vector<vector<int>> &A, vector<vector<int>> &B, int N, int oxa, int oya, int oxb, int oyb) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[oxa + i][oya + j] != B[oxb + N - 1 - i][oyb + N - 1 - j])
				return false;
		}
	}
	return true;
}

bool test3(vector<vector<int>> &A, vector<vector<int>> &B, int N, int oxa, int oya, int oxb, int oyb) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[oxa + i][oya + j] != B[oxb + N - 1 - j][oyb + i])
				return false;
		}
	}
	return true;
}

bool test(vector<vector<int>> &A, vector<vector<int>> &B, int N, int oxa, int oya, int oxb, int oyb) {
	if (1 == N) {
		return A[0][0] == B[0][0];
	} else if (N & 0x1 || 2 == N) {
		if (test0(A, B, N, oxa, oya, oxb, oyb)) return true;
		if (test1(A, B, N, oxa, oya, oxb, oyb)) return true;
		if (test2(A, B, N, oxa, oya, oxb, oyb)) return true;
		if (test3(A, B, N, oxa, oya, oxb, oyb)) return true;
	} else {
		if (test0(A, B, N, oxa, oya, oxb, oyb)) return true;
		unordered_map<int, int> table;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				table[A[oxa + i][oya + j]]++;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				table[B[oxb + i][oyb + j]]--;
				if (table[B[oxb + i][oyb + j]] == 0)
					table.erase(B[oxb + i][oyb + j]);
			}
		}
		if (!table.empty())
			return false;
		if (test(A, B, N / 2, oxa, oya, oxb + N / 2, oyb) && test(A, B, N / 2, oxa + N / 2, oya, oxb + N / 2, oyb + N / 2) &&
			test(A, B, N / 2, oxa + N / 2, oya + N / 2, oxb, oyb + N / 2) && test(A, B, N / 2, oxa, oyb + N / 2, oxb, oyb))
			return true;
		else if (test(A, B, N / 2, oxa, oya, oxb + N / 2, oyb + N / 2) && test(A, B, N / 2, oxa + N / 2, oya, oxb, oyb + N / 2) &&
			test(A, B, N / 2, oxa + N / 2, oya + N / 2, oxb, oyb) && test(A, B, N / 2, oxa, oyb + N / 2, oxb + N / 2, oyb))
			return true;
		else if (test(A, B, N / 2, oxa, oya, oxb, oyb + N / 2) && test(A, B, N / 2, oxa + N / 2, oya, oxb, oyb) &&
			test(A, B, N / 2, oxa + N / 2, oya + N / 2, oxb + N / 2, oyb) && test(A, B, N / 2, oxa, oyb + N / 2, oxb + N / 2, oyb + N / 2))
			return true;
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<vector<int>> A(N), B(N);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int tmp;
				cin >> tmp;
				A[j].push_back(tmp);
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int tmp;
				cin >> tmp;
				B[j].push_back(tmp);
			}
		}
		bool flag = test(A, B, N, 0, 0, 0, 0);
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
