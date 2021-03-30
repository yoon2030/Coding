#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int N;
string str;
int result = INT_MIN;

int cal(int a, int b, char oper) {

	int result = a;
	switch (oper) {
	case '+':result += b; break;
	case '*':result *= b; break;
	case '-':result -= b; break;
	}
	return result;
}

void dfs(int idx, int cur) {
	if (idx > N - 1) {
		result = max(result, cur);
		return;
	}
	char oper;
	if (idx == 0)oper = '+';
	else oper = str[idx - 1];
	if (idx + 2 < N) {
		int result_2 = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx+4, cal(cur,result_2,oper));
	}
	dfs(idx + 2, cal(cur,str[idx]-'0', oper));
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> str;

	dfs(0, 0);

	cout << result;
}