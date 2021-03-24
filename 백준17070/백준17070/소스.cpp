#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
int result = 0;
int arr[17][17];
int dir1[3] = { 0,1,1 };
int dir2[3] = { 1,1,0 };

bool check(int x1, int y1, int t) {
	if (t == 1) {
		if (x1 > 0 && x1 <= N && y1 > 0 && y1 <= N && arr[x1][y1] == 0) {
			return true;
		}
	}
	else if (t == 2) {
		if (x1 > 0 && x1 <= N && y1 > 0 && y1 <= N && arr[x1][y1] == 0 && arr[x1 - 1][y1] == 0 && arr[x1][y1 - 1] == 0) {
			return true;
		}
	}
	else {
		if (x1 > 0 && x1 <= N && y1 > 0 && y1 <= N && arr[x1][y1] == 0) {
			return true;
		}
	}

	return false;
}
//1 가로 2 대각선 3 세로
void dfs(int x, int y, int ty) {
	int x1, y1;
	if (x == N && y == N && arr[N][N] == 0) {
		result++;
	}
	else if (ty == 1) {
		for (int i = 0; i <= 1; i++) {
			x1 = x + dir1[i];
			y1 = y + dir2[i];
			if (check(x1, y1, i + 1)) {
				dfs(x1, y1, i + 1);
			}
		}
	}
	else if (ty == 2) {
		for (int i = 0; i <= 2; i++) {
			x1 = x + dir1[i];
			y1 = y + dir2[i];
			if (check(x1, y1, i + 1)) {
				dfs(x1, y1, i + 1);
			}
		}
	}
	else if (ty == 3) {
		for (int i = 1; i <= 2; i++) {
			x1 = x + dir1[i];
			y1 = y + dir2[i];
			if (check(x1, y1, i + 1)) {
				dfs(x1, y1, i + 1);
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	dfs(1, 2, 1);
	cout << result;
}