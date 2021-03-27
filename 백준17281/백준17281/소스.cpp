#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define player_num 9
int N;
int arr[52][9];
bool player_select[9], is_ground[3];
vector <int> player;
int result = 0;
int ans;


void move(int n) {	
	for (int i = 2; i >= 0; i--) {
		if (is_ground[i]) {
			if (n + i >= 3)ans++;
			else is_ground[n + i] = true;
			is_ground[i] = false;
		}
	}
	if (n == 4)ans++;
	else is_ground[n-1] = true;
}

void play() {
	int idx=0;
	int out;
	for (int i = 0; i < N; i++) {
		out = 0;
		memset(is_ground, false, sizeof(is_ground));
		while (true) {
			if (idx >= player_num)idx = 0;
			if (arr[i][player[idx]] == 0) {
				out++;
				if (out == 3) {
					idx++;
					break;
				}
			}
			else move(arr[i][player[idx]]);
			idx++;
		}
	}
	result = max(result,ans);
}

void select() {
	if (player.size() == player_num - 1) {
		player.insert(player.begin() + 3, 0);
		ans = 0;
		play();
		player.erase(player.begin() + 3);
		return;
	}
	for (int i = 1; i < player_num; i++) {
		if (!player_select[i]) {
			player_select[i] = true;
			player.push_back(i);
			select();
			player.pop_back();
			player_select[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < player_num; j++) {
			cin >> arr[i][j];
		}
	}
	select();
	cout << result;


}