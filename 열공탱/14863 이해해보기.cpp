// 백준 kajebiii 님 14863 서울에서 경산까지 코드
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e2 + 10, MAX_K = 1e5 + 100;

int N, K;
int Dy[MAX_N][MAX_K];
int main() {
	cin >> N >> K;
	for (int p = 0; p <= N; p++) for (int i = 0; i<MAX_K; i++) Dy[p][i] = -INF;
	Dy[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int s = 0; s<2; s++) {
			int m, w; scanf_s("%d%d", &m, &w);
			for (int k = 0; k <= K - m; k++) 
				Dy[i][k + m] = max(Dy[i][k + m], Dy[i - 1][k] + w);
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= K; i++) ans = max(ans, Dy[N][i]);
	printf("%d\n", ans);
	return 0;
}
