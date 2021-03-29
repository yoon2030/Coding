#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int people[12];	// 각 지역에 있는 인구수
int area[12];	//각 지역에 연결된 지역의 갯수
bool arr[12][12]; //지역간의 연결 여부
bool arr_select[12]; //dfs를 위한 지역 선택
bool visit[12];
int result = 987654321;


bool check_connect(vector<int> V, bool T) {
	queue<int> Q;
	Q.push(V[0]);
	memset(visit, false, sizeof(visit));
	visit[V[0]] = true;
	int cnt = 1;
	while (Q.empty() == 0) {
		int x = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[x][i] == true && arr_select[i] == T && visit[i] == false) {
				Q.push(i);
				cnt++;
				visit[i] = true;
			}
		}
	}
	if (cnt == V.size())return true;
	else return false;

}

bool check() {
	vector <int> A, B; //A는 선택된 지역구, B는 선택 안된 지역구
	for (int i = 1; i <= N; i++) {
		if (arr_select[i] == true)A.push_back(i);
		else B.push_back(i);
	}
	if (A.size() == 0 || B.size() == 0)return false;

	bool A_result = check_connect(A, true);
	if (A_result == false)return false;
	bool B_result = check_connect(B, false);
	if (B_result == false)return false;

	return true;

}

void cal() {
	int A_state = 0;
	int B_state = 0;
	for (int i = 1; i <= N; i++) {
		if (arr_select[i] == true)A_state+=people[i];
		else B_state+=people[i];
	}
	int ans = abs(A_state - B_state);
	result = min(result, ans);
}

void dfs(int idx, int cnt) {
	if (cnt >= 1) {
		if (check()) {
			cal();
		}
	}
	for (int i = idx; i <= N; i++) {
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
	int k;
	memset(arr_select, false, sizeof(arr_select));
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> people[i];

	for (int i = 1; i <= N; i++) {
		cin >> area[i];
		for (int j = 1; j <= area[i]; j++) {
			cin >> k;
			arr[i][k] = true;
			arr[k][i] = true;
		}
	}
	dfs(1, 0);

	if (result == 987654321)cout << -1;
	else cout << result;
}