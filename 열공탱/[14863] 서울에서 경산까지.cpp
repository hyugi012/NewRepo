#include <iostream>
#include <algorithm>
#define IMPOSSIBLE -987654321
using namespace std;

struct data_type {
	int time, money;
};

data_type info[2][100];
int dp[100][100001];
int N, K;

int solve(int, int);

int main()
{
	cin >> N >> K;

	memset(dp, -1, sizeof(dp));

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 2; i++) { // 0 도보, 1 자전거
			cin >> info[i][n].time;
			cin >> info[i][n].money;
		}
	}
	cout <<  solve(0, K) << endl;
}

int solve(int n, int k)
{
	if (n == N) return 0;
	if (k <= 0) return IMPOSSIBLE;

	int& ret = dp[n][k];
	if (ret != -1) return ret;
	ret = IMPOSSIBLE;

	if (k - info[0][n].time >= 0 && solve(n + 1, k - info[0][n].time) != IMPOSSIBLE)
		ret = max(ret, solve(n + 1, k - info[0][n].time) + info[0][n].money);
	if (k - info[1][n].time >= 0 && solve(n + 1, k - info[1][n].time) != IMPOSSIBLE)
		ret = max(ret, solve(n + 1, k - info[1][n].time) + info[1][n].money);
	return ret;
}