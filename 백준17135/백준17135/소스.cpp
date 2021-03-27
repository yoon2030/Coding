#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

int N, M, D;
int result = 0;
int arr[17][17];	//건들면 안되는 맵
int dx[3] = { -1,0,1 }; //좌 상 우
int dy[3] = { 0,-1,0 };
queue<pair<int, int>> q;

void solve(int x, int y, int z) {
	int arr_copy[17][17];
	bool check[16][16];
	bool visit[16][16];
	int archer[3] = { x,y,z };  //x축가로			x가 세로고	y가 가로야
	int pos = N + 1;	//궁수의 위치 y축세로
	int kill = 0;

	for(int i=1;i<=N;i++)
		for (int j = 1; j <= M; j++) {
			arr_copy[i][j] = arr[i][j];
			check[i][j] = false;
		}
	while (pos > 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= M; k++)
					visit[j][k] = false;

			q = queue<pair<int, int>>();
			int init_x = archer[i];
			int init_y = pos - 1;
			q.push({init_x,init_y});

			while (!q.empty()) {
				int now_x = q.front().first;		//가로축
				int now_y = q.front().second;		//세로축
				q.pop();

				visit[now_y][now_x] = true;		//세로,가로 순서대로 들어가야됨

				if (arr_copy[now_y][now_x] == 1) {//적 발견
					check[now_y][now_x] = true;
					break;
				}
				for (int j = 0; j < 3; j++) {
					int next_x = now_x + dx[j];
					int next_y = now_y + dy[j];
					if(next_x>=1 && next_x <=M && next_y >=1 && next_y<=N)
						if ((abs(archer[i] - next_x) + abs(pos - next_y)) <= D) 
							if (!visit[next_y][next_x])
								q.push({ next_x,next_y });
				}
			}
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (check[i][j])
					arr_copy[i][j] = 0;
		pos--;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (check[i][j]) kill++;

	result = max(result, kill);

}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i <= M; i++) {
		for (int j = i + 1; j <= M; j++) {
			for (int z = j + 1; z <= M; z++) {
				solve(i, j, z);
			}
		}
	}

	cout << result<<endl;
}