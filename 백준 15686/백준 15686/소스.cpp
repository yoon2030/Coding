#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[52][52];
int N, M;
int result = 987654321;
int ans;
int chicken_dis[52][52];
bool arr_select[14];
vector<pair<int, int>> chicken;


void cal() {
	int x1, y1; //치킨집의 좌표
	int dis;
	int dis_result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) {
				ans = 987654321;
				for (int z = 0; z < chicken.size(); z++) {	
					if (arr_select[z]) {
						x1 = chicken[z].first;
						y1 = chicken[z].second;
						dis = abs(i - x1) + abs(j - y1);
						ans = min(ans, dis);
					}
				}
				dis_result += ans;	
			}
		}
	}
	result = min(result, dis_result);
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		cal();
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (arr_select[i])continue;
		arr_select[i] = true;
		dfs(i, cnt + 1);
		arr_select[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				arr[i][j] = 0;
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);
	cout << result;
}
