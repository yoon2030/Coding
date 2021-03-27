#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Turn_info {
	int R, C, S;
};


int arr[52][52];
int arr_copy[52][52];
int arr_copy2[52][52];
int N, M, K;
int result = 987654321;
int ans=0;
bool Select[6];
vector<Turn_info> V;
vector<int> Turn_Order;



void rotate(Turn_info T) {

	int x1 = T.R - T.S;		//마지막에 +1
	int y1 = T.C - T.S;
	int x2 = T.R + T.S;		//마지막에 -1
	int y2 = T.C + T.S;
	int num = x2 - x1;
	for (int i = 1; i <= N; i++)		//복사
		for (int j = 1; j <= M; j++)
			arr_copy2[i][j] = arr_copy[i][j];
	while (num > 0) {
		if (x1 == x2 && y1 == y2)break;
		for (int i = 1; i <= num; i++) {
			arr_copy[x1][y1 + i] = arr_copy2[x1][y1+i-1];
		}
		for (int i = 1; i <= num; i++) {
			arr_copy[x1 + i][y2] = arr_copy2[x1+i-1][y2];
		}
		for (int i = 1; i <= num; i++) {
			arr_copy[x2][y2 - i] = arr_copy2[x2][y2 - i + 1];
		}
		for (int i = 1; i <= num; i++) {
			arr_copy[x2 - i][y1] = arr_copy2[x2 - i + 1][y1];
		}

		x1 += 1; 
		y1 += 1; 
		x2 -= 1; 
		y2 -= 1;
		num -= 2;
		
	}

}
void DFS(int cnt) {
	if (cnt == K) {
		for (int i = 1; i <= N; i++)		//복사
			for (int j = 1; j <= M; j++)
				arr_copy[i][j] = arr[i][j];

		for (int i = 0; i < Turn_Order.size(); i++) {
			int Order = Turn_Order[i];
			rotate(V[Order]);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				ans += arr_copy[i][j];
			}
			
			result = min(result, ans);
			ans = 0;
		}
	}
	for (int i = 0; i < V.size(); i++) {
		if (Select[i] == true)continue;
		Select[i] = true;
		Turn_Order.push_back(i);
		DFS(cnt + 1);
		Turn_Order.pop_back();
		Select[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, c, s;

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		V.push_back({ r,c,s });
	}
	DFS(0);

	cout << result;
}