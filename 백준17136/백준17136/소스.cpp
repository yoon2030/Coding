#include <iostream>
#include <algorithm>
using namespace std;

int arr[11][11];
int total = 0;
int result = 987654321;
int paper[5] = { 0,0,0,0,0 };

void attach(int x, int y, int s, bool is_attach) {
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			arr[i][j] = is_attach;
		}
	}
}

bool can_attach(int x, int y, int s) {
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (!arr[i][j])return false;
		}
	}
	return true;
}

void DFS(int x, int y, int attach_cnt) {
	while (arr[x][y] == 0) {
		y++;
		if (y >= 10) {
			x++;
			if (x >= 10) {
				result = min(result, attach_cnt);
				return;
			}
			y = 0;
		}
	}

	if (result <= attach_cnt)return;

	for (int s = 5; s > 0; s--) {
		if (x + s > 10 || y + s > 10 || paper[s-1] == 5)continue;
		if (can_attach(x,y,s)) {
			attach(x, y, s, 0);
			paper[s-1]++;
			DFS(x, y, attach_cnt + 1);
			attach(x, y, s, 1);
			paper[s-1]--;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
			if (arr[i][j])total++;
		}
	}
	if (total == 100) {
		cout << "4";
		return 0;
	}
	DFS(0, 0, 0);
	if (result == 987654321)cout << -1;
	else cout << result;

}