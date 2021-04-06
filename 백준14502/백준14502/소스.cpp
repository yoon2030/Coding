#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int N, M, space;
int result = 0;
vector <pair<int, int>> Empty, virus;
bool check[64];
bool visit[9][9];
int map[9][9];
int copy_map[9][9];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void map_copy(){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void BFS(int x, int y) {
	queue <pair<int, int>> Q;
	visit[x][y] = true;
	Q.push(make_pair(x, y));
	while (Q.empty() == false) {
		int a = Q.front().first;
		int b = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (visit[nx][ny] == false && copy_map[nx][ny] == 0) {
					copy_map[nx][ny] = 2;
					visit[nx][ny] = true;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void spread_virus() {
	int cnt = 0;
	map_copy();
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < space; i++) {
		if (cnt == 3)break;
		if (check[i]) {
			int x = Empty[i].first;
			int y = Empty[i].second;
			copy_map[x][y] = 1;
			cnt++;
		}
	}
	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		BFS(x, y);
	}
}

void check_area() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0)count++;
		}
	}
	result = max(result, count);
}
void make_wall(int idx, int cnt) {
	if (cnt == 3) {
		spread_virus();
		check_area();
		return;
	}
	for (int i = idx; i < space; i++) {
		if (check[i])continue;
		check[i] = true;
		make_wall(i, cnt + 1);
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)Empty.push_back(make_pair(i, j));
			else if (map[i][j] == 2)virus.push_back(make_pair(i, j));
		}
	}
	space = Empty.size();
	make_wall(0, 0);
	cout << result;
}
