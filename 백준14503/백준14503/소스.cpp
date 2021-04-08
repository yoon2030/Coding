#include <iostream>

using namespace std;

int N, M;
int r, c, d;
int map[51][51];	
int clean_count = 0;
int dx[4] = {-1,0,1,0};		
int dy[4] = {0,1,0,-1};
void solution(int a,int b,int c) {
	int x = a;
	int y = b;
	int dir = c;
	map[x][y] = 2;
	clean_count++;
	int nx, ny, nd;
	while(true){
		int tmp_dir = dir;
		int d_count = 0;
		bool clean = false;
		for (int i = 0; i < 4; i++) {
			nd = dir - 1;
			if (nd < 0)nd = 3;
			nx = x + dx[nd];
			ny = y + dy[nd];
			if (map[nx][ny] == 0) {
				clean = true;
				break;
			}
			else if (map[nx][ny] == 1 || map[nx][ny]==2 || (nx<0 || ny<0||nx>=N||ny>=M)) {
				dir = nd;
				d_count++;
			}
		}
		if (clean == true) {
			map[nx][ny] = 2;
			clean_count++;
			dir = nd;
		}
		if (d_count == 4) {
			nx = x - dx[tmp_dir];
			ny = y - dy[tmp_dir];
			dir = tmp_dir;
			if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || map[nx][ny] == 1)break;
		}
		x = nx;
		y = ny;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	solution(r, c, d);
	cout << clean_count;
}