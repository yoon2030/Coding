#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int map[9][9];
int copy_map[9][9];
int result = 987654321;
vector <pair<int, int>> cctv_dir;	//first는 cctv 번호 second는 방향
vector <pair<int, int>> cctv_location;

void map_copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void cal() {
	int sum = 0;
	for(int i=0;i<N;i++){
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0)sum++;
		}
	}
	result = min(result, sum);
}
void Right(int x, int y)
{
	for (int i = y + 1; i < M; i++)
	{
		if (copy_map[x][i] == 6) break;
		if (1 <= copy_map[x][i] && copy_map[x][i] <= 5) continue;

		copy_map[x][i] = -1;
	}
}

void Left(int x, int y)
{
	for (int i = y - 1; i >= 0; i--)
	{
		if (copy_map[x][i] == 6) break;
		if (1 <= copy_map[x][i] && copy_map[x][i] <= 5) continue;

		copy_map[x][i] = -1;
	}
}

void Down(int x, int y)
{
	for (int i = x + 1; i < N; i++)
	{
		if (copy_map[i][y] == 6) break;
		if (1 <= copy_map[i][y] && copy_map[i][y] <= 5) continue;

		copy_map[i][y] = -1;
	}
}

void Up(int x, int y)
{
	for (int i = x - 1; i >= 0; i--)
	{
		if (copy_map[i][y] == 6) break;
		if (1 <= copy_map[i][y] && copy_map[i][y] <= 5) continue;

		copy_map[i][y] = -1;
	}
}


void watch() {
	map_copy();
	for (int i = 0; i < cctv_dir.size(); i++) {
		if (cctv_dir[i].first == 1) {
			if (cctv_dir[i].second == 0)Right(cctv_location[i].first, cctv_location[i].second);
			else if (cctv_dir[i].second == 1)Left(cctv_location[i].first, cctv_location[i].second);
			else if (cctv_dir[i].second == 2)Down(cctv_location[i].first, cctv_location[i].second);
			else if (cctv_dir[i].second == 3)Up(cctv_location[i].first, cctv_location[i].second);
		}
		else if (cctv_dir[i].first == 2) {
			if (cctv_dir[i].second == 0 || cctv_dir[i].second == 1) {
				Right(cctv_location[i].first, cctv_location[i].second);
				Left(cctv_location[i].first, cctv_location[i].second);
			}
			else if (cctv_dir[i].second == 2 || cctv_dir[i].second == 3) {
				Up(cctv_location[i].first, cctv_location[i].second);
				Down(cctv_location[i].first, cctv_location[i].second);
			}
		}
		else if (cctv_dir[i].first == 3) {
			if (cctv_dir[i].second == 0) {
				Up(cctv_location[i].first, cctv_location[i].second);
				Right(cctv_location[i].first, cctv_location[i].second);
			}
			else if (cctv_dir[i].second == 1) {
				Right(cctv_location[i].first, cctv_location[i].second);
				Down(cctv_location[i].first, cctv_location[i].second);
			}
			else if (cctv_dir[i].second == 2) {
				Down(cctv_location[i].first, cctv_location[i].second);
				Left(cctv_location[i].first, cctv_location[i].second);
			}
			else if (cctv_dir[i].second == 3) {
				Left(cctv_location[i].first, cctv_location[i].second);
				Up(cctv_location[i].first, cctv_location[i].second);
			}
		}
		else if (cctv_dir[i].first == 4) {
			if (cctv_dir[i].second == 0) {
				Left(cctv_location[i].first, cctv_location[i].second);
				Up(cctv_location[i].first, cctv_location[i].second);
				Right(cctv_location[i].first, cctv_location[i].second);
			}
			else if (cctv_dir[i].second == 1) {
				Up(cctv_location[i].first, cctv_location[i].second);
				Right(cctv_location[i].first, cctv_location[i].second);
				Down(cctv_location[i].first, cctv_location[i].second);
			}
			else if (cctv_dir[i].second == 2) {
				Right(cctv_location[i].first, cctv_location[i].second);
				Down(cctv_location[i].first, cctv_location[i].second);
				Left(cctv_location[i].first, cctv_location[i].second);
			}
			else if (cctv_dir[i].second == 3) {
				Down(cctv_location[i].first, cctv_location[i].second);
				Left(cctv_location[i].first, cctv_location[i].second);
				Up(cctv_location[i].first, cctv_location[i].second);
			}
		}
		else if (cctv_dir[i].first == 5) {
			Right(cctv_location[i].first, cctv_location[i].second);
			Down(cctv_location[i].first, cctv_location[i].second);
			Left(cctv_location[i].first, cctv_location[i].second);
			Up(cctv_location[i].first, cctv_location[i].second);
		}
	}
}

void solution(int cnt) {
	if (cnt == cctv_dir.size()) {
		watch();
		cal();
		return;
	}
	cctv_dir[cnt].second = 0;
	solution(cnt + 1);
	cctv_dir[cnt].second = 1;
	solution(cnt + 1);
	cctv_dir[cnt].second = 2;
	solution(cnt + 1);
	cctv_dir[cnt].second = 3;
	solution(cnt + 1);
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (1<=map[i][j] && map[i][j]<=5) {
				cctv_dir.push_back(make_pair(map[i][j],-1));
				cctv_location.push_back(make_pair(i, j));
			}
		}
	}
	solution(0);
	cout << result;
}