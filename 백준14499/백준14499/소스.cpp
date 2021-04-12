#include <iostream>
#include <vector>

using namespace std;

int map[21][21];
int N, M, K;
int x, y;
vector <int> dir;
vector <int> dice_1; //세로방향
vector <int> dice_2; //가로방향

void play() {
	int nx=x;
	int ny=y;

	for (int i = 0; i < K; i++) {
		if (dir[i] == 1) {
			if (ny + 1 >= M) continue;
			ny += 1;
			dice_2.insert(dice_2.begin(), dice_2[3]);
			dice_2.pop_back();
			if (map[nx][ny] == 0)map[nx][ny] = dice_2[3];
			else if (map[nx][ny] != 0) {
				dice_2[3] = map[nx][ny];
				map[nx][ny] = 0;
			}
			dice_1[1] = dice_2[1];
			dice_1[3] = dice_2[3];
			cout << dice_1[1] << endl;
		}
		else if (dir[i] == 2) {
			if (ny - 1 < 0)continue;
			ny -= 1;
			dice_2.push_back(dice_2[0]);
			dice_2.erase(dice_2.begin());
			if (map[nx][ny] == 0)map[nx][ny] = dice_2[3];
			else if (map[nx][ny] != 0) {
				dice_2[3] = map[nx][ny];
				map[nx][ny] = 0;
			}
			dice_1[1] = dice_2[1];
			dice_1[3] = dice_2[3];
			cout << dice_1[1]<<endl;

		}
		else if (dir[i] == 3) {
			if (nx - 1 < 0)continue;
			nx -= 1;
			dice_1.push_back(dice_1[0]);
			dice_1.erase(dice_1.begin());
			if (map[nx][ny] == 0)map[nx][ny] = dice_1[3];
			else if (map[nx][ny] != 0) {
				dice_1[3] = map[nx][ny];
				map[nx][ny] = 0;
			}
			dice_2[1] = dice_1[1];
			dice_2[3] = dice_1[3];
			cout << dice_1[1] << endl;
		}
		else if (dir[i] == 4) {
			if (nx + 1 >= N)continue;
			nx += 1;
			dice_1.insert(dice_1.begin(), dice_1[3]);
			dice_1.pop_back();
			if (map[nx][ny] == 0)map[nx][ny] = dice_1[3];
			else if (map[nx][ny] != 0) {
				dice_1[3] = map[nx][ny];
				map[nx][ny] = 0;
			}
			dice_2[1] = dice_1[1];
			dice_2[3] = dice_1[3];
			cout << dice_1[1] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	map[x][y] = 0;
	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		dir.push_back(num);
	}
	for (int i = 0; i < 4; i++)dice_1.push_back(0);
	for (int i = 0; i < 4; i++)dice_2.push_back(0);

	play();
}

