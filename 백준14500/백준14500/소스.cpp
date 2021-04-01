#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[502][502];
bool visit[502][502];
int result = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y, int sum, int cnt) {
	visit[x][y] = true;
	if (cnt == 3) {
		result = max(result, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
		if (visit[nx][ny])continue;
		dfs(nx, ny, sum + map[nx][ny], cnt + 1);
		visit[nx][ny] = false;
	}
}

void sh1(int x, int y) { // た
	int sum = 0;
	sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
	result = max(result, sum);
}
void sh2(int x, int y) { // っ
	int sum = 0;
	sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1];
	result = max(result, sum);
}
void sh3(int x, int y) { // で
	int sum = 0;
	sum = map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x - 1][y - 1];
	result = max(result, sum);
}
void sh4(int x, int y) { // ぬ
	int sum = 0;
	sum = map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x - 1][y + 1];
	result = max(result, sum);
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visit, false, sizeof(visit));
			dfs(i, j, map[i][j], 0);
			if (i + 1 < N && j + 2 < M)sh1(i, j);
			if (i - 1 >= 0 && j + 2 < M)sh2(i, j);
			if (i - 2 >= 0 && j - 1 >= 0)sh3(i, j);
			if (i - 2 >= 0 && j + 1 < M)sh4(i, j);
		}
	}
	cout << result;

}