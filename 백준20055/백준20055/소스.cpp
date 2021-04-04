#include <iostream>
#include <vector>

using namespace std;

int N, K;

vector <int> negu;
vector <bool> con;


void rotate() {
	negu.insert(negu.begin(), negu.back());
	negu.pop_back();

	con.insert(con.begin(), con.back());
	con.pop_back();

	con[N - 1] = false;
}
void move() {
	for (int i = N - 2; i >= 0; i--) {
		if ((!con[i + 1]) && con[i] && (negu[i + 1] > 0)) {
			con[i + 1] = true;
			con[i] = false;
			negu[i + 1]--;
		}
	}
	con[N - 1] = false;
}
void put_robot() {
	if ((!con[0]) && (negu[0] > 0)) {
		con[0] = true;
		negu[0]--;
	}
}
int check() {
	int count = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (negu[i] == 0)count++;
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	int step = 1;
	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++) {
		cin >> num;
		negu.push_back(num);
		con.push_back(false);
	}

	while (true) {
		rotate();
		move();
		put_robot();
		int c = check();
		if (c >= K) {
			cout << step;
			break;
		}
		step++;
	}
	return 0;
}