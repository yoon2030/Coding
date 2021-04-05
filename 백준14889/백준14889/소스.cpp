#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N;
int arr[23][23];
int result = 987654321;
bool arr_select[23];

void cal() {
	int start = 0;
	int link = 0;
	int A[11];
	int A_cnt = 0;
	int B[11];
	int B_cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (arr_select[i]) {
			A[A_cnt] = i;
			A_cnt++;
		}
		else {
			B[B_cnt] = i;
			B_cnt++;
		}
	}
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			start += arr[A[i]][A[j]] + arr[A[j]][A[i]];
			link += arr[B[i]][B[j]] + arr[B[j]][B[i]];
		}
	}

	result = min(result, abs(link - start));

}

void dfs(int idx, int cnt) {
	if (cnt == N / 2) {
		cal();
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (arr_select[i])continue;
		arr_select[i] = true;
		dfs(i + 1, cnt + 1);
		arr_select[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(1, 0);
	cout << result;
}